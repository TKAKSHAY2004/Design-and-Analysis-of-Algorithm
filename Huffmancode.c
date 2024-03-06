#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct MinHeapNode {
    char data; 
    unsigned freq;

    struct MinHeapNode *left, *right; 
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};
void printCodes(struct MinHeapNode* root, string str) {
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
void HuffmanCodes(vector<char>& data, vector<unsigned>& freq) {
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i = 0; i < data.size(); ++i)
        minHeap.push(new MinHeapNode{data[i], freq[i], nullptr, nullptr});
    while (minHeap.size() != 1) {
        left = minHeap.top(); minHeap.pop();
        right = minHeap.top(); minHeap.pop();
        top = new MinHeapNode{'$', left->freq + right->freq, left, right};
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;
    vector<char> data(n);
    vector<unsigned> freq(n);
    cout << "Enter characters and their frequencies:\n";
    for (int i = 0; i < n; ++i)
        cin >> data[i] >> freq[i];
    HuffmanCodes(data, freq);
    return 0;
}

/*output
Enter the number of characters: 4
Enter characters and their frequencies:
a 8
b 4
c 21
d 5
a: 00
b: 010
d: 011
c: 1
*/

