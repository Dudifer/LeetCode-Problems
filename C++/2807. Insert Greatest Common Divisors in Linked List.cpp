/**
Given the head of a linked list head, in which each node contains an integer value. Between every 
pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
Return the linked list after insertion.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both
numbers.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next == nullptr){
            return head;
        }
        // iterate down from half val to current gcd ()
        ListNode* currPointer = head;
        ListNode* nextPointer = head->next; NEED TO MAKE SO WHILE GOES THROUGH W LAST NODE, DO BY
        STARTING ITER W 0-ETH AND 1ST AS NXT
        long long max; 
        long long min;
        int remainder;
        do{
            if (currPointer->val > nextPointer->val){
                max = currPointer->val;
                min = nextPointer->val;
            }
            else {
                max = nextPointer->val;
                min = currPointer->val;
            }
            remainder = max % min;
            while (remainder != 0){
                std::cout << "max: " << max << std::endl;
                std::cout << "min: " << min << std::endl;
                std::cout << "remainder: " << remainder << std::endl;
                if (remainder % min == 0){
                    break;
                }
                max = min;
                min = remainder;
                remainder = max - min;
            }

            ListNode* gcdNode =  new ListNode(min, nextPointer);
            currPointer->next = gcdNode;
            currPointer = gcdNode->next;
            nextPointer = nextPointer->next;
        } while (currPointer->next != nullptr);
        
        return head;
    }
};