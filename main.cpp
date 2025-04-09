#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* node) {
        if (node == nullptr) {
            return node;
        }
        ListNode* head = node;
        while (node->next != nullptr) {
            if (node->val == node->next->val) {
                node->next = node->next->next; // Skip the duplicate node
            } else {
                node = node->next; // Move to the next distinct node
            }
        }
        return head;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << ",";
        }
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    // Example 1
    vector<int> values1 = {1, 1, 2};
    ListNode* head1 = createLinkedList(values1);
    cout << "Input: head = [1,1,2]" << endl;
    ListNode* result1 = solution.deleteDuplicates(head1);
    cout << "Output: ";
    printLinkedList(result1);

    // Example 2
    vector<int> values2 = {1, 1, 2, 3, 3};
    ListNode* head2 = createLinkedList(values2);
    cout << "Input: head = [1,1,2,3,3]" << endl;
    ListNode* result2 = solution.deleteDuplicates(head2);
    cout << "Output: ";
    printLinkedList(result2);

    return 0;
}
