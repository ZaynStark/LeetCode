#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class ThroneInheritance {
public:
    struct ListNode
    {
        string name;
        ListNode *next;
        ListNode *last;
        bool isDeleted = false;
        ListNode(string name) : name(name), next(nullptr){}
    };
    unordered_map<string,ListNode> map;
    ListNode head = ListNode("null");

    ThroneInheritance(string kingName) {

    }
    
    void birth(string parentName, string childName) {

    }
    
    void death(string name) {

    }
    
    vector<string> getInheritanceOrder() {

    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */