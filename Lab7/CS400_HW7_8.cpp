// CS400_HW7_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// TODO: Huffman tree node
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// TODO: Comparison struct for priority queue
struct CompareNodes {
    bool operator()(Node* left, Node* right) {
        return (left->freq > right->freq);
    }
};

// TODO: Function to build the Huffman tree
Node* buildHuffmanTree(const unordered_map<char, int>& frequencies) {
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;

    for (const auto& entry : frequencies) {
        pq.push(new Node(entry.first, entry.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    if (!pq.empty()) {
        Node* root = pq.top();
        pq.pop();
        return root;
    }

    return nullptr;
}

// TDO: Function to traverse the Huffman tree and generate codes
void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        codes[root->ch] = code;
    }

    generateHuffmanCodes(root->left, code + "0", codes);
    generateHuffmanCodes(root->right, code + "1", codes);
}

// hw7
// TODO: Function to perform Huffman coding on the input string
string huffmanEncode(Node* root, const string& input, unordered_map<char, string> codes) {
    generateHuffmanCodes(root, "", codes);

    string encodedString = "";
    for (char c : input) {
        encodedString += codes[c];
    }

    return encodedString;
}

// hw8
// TODO: Function to perform Huffman decoding on the encoded string
string huffmanDecode(const string& encodedString, const unordered_map<string, char>& decode_dict) {
    string result = "";
    string temp = "";

    for (int i = 0; i < encodedString.size(); i++) {
        temp += encodedString[i];

        if (decode_dict.find(temp) != decode_dict.end()) {
            result += decode_dict.at(temp);
            temp = "";
        }
    }

    return result;
}


int main() {
    string input = "ABBCCCDDDD";

    unordered_map<char, int> frequencies;
    for (char c : input) {
        frequencies[c]++;
    }

    Node* root = buildHuffmanTree(frequencies);
    unordered_map<char, string> codes;
    generateHuffmanCodes(root, "", codes);

    // print codes 
    for (auto i : codes) {
        cout << "key: " << i.first << "\tvalue: " << i.second << endl;
    }

    unordered_map<string, char> decode_dict;
    for (auto i : codes) {
        decode_dict[i.second] = i.first;
    }

    for (auto i : decode_dict) {
        cout << "key: " << i.first << "\tvalue: " << i.second << endl;
    }

    string encodedString = huffmanEncode(root, input, codes);
    cout << "Encoded string: " << encodedString << endl;

    string decodedString = huffmanDecode(encodedString, decode_dict);
    cout << "Decoded string: " << decodedString << endl;

    delete root;
}
