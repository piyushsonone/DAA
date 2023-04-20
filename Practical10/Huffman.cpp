#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// Huffman tree node
class HuffmanNode {
public:
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }

    bool isLeaf() const {
        return !left && !right;
    }
};

// Compare two nodes based on frequency
class Compare {
public:
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

// Huffman encoding and decoding class
class Huffman {
public:
    // Huffman encoding
    string encode(const string& input) {
        // Calculate frequency of each character
        unordered_map<char, int> freq;
        for (char c : input) {
            freq[c]++;
        }

        // Create a priority queue to store Huffman tree nodes
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
        for (auto p : freq) {
            pq.push(new HuffmanNode(p.first, p.second));
        }

        // Build the Huffman tree
        while (pq.size() > 1) {
            HuffmanNode* left = pq.top();
            pq.pop();

            HuffmanNode* right = pq.top();
            pq.pop();

            HuffmanNode* node = new HuffmanNode('$', left->freq + right->freq);
            node->left = left;
            node->right = right;

            pq.push(node);
        }

        root = pq.top();

        // Traverse the Huffman tree and generate codes
        unordered_map<char, string> codes;
        generateCodes(root, "", codes);

        // Encode the input string using the generated codes
        string output;
        for (char c : input) {
            output += codes[c];
        }

        return output;
    }

    // Huffman decoding
    string decode(const string& input) {
        string output;
        HuffmanNode* curr = root;

        for (char c : input) {
            if (c == '0') {
                curr = curr->left;
            } else {
                curr = curr->right;
            }

            // Leaf node, store the decoded character and reset the current node
            if (curr->isLeaf()) {
                output += curr->data;
                curr = root;
            }
        }

        return output;
    }

private:
    HuffmanNode* root;

    // Traverse the Huffman tree and store codes in a map
    void generateCodes(HuffmanNode* node, string code, unordered_map<char, string>& codes) {
        if (node == nullptr) {
            return;
        }

        // Leaf node, store the code
        if (node->isLeaf()) {
            codes[node->data] = code;
        }

        generateCodes(node->left, code + "0", codes);
        generateCodes(node->right, code + "1", codes);
    }
};

int main() {
    Huffman huffman;

    string input = "hello world";

    string encoded = huffman.encode(input);
    cout << "Encoded: " << encoded << endl;

    string decoded = huffman.decode(encoded);
    cout << "Decoded: " << decoded << endl;

    return 0;
}
