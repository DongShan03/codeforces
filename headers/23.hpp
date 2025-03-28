/**
 * Definition for singly-linked list.
 * struct ListNode23 {
 *     int val;
 *     ListNode23 *next;
 *     ListNode23() : val(0), next(nullptr) {}
 *     ListNode23(int x) : val(x), next(nullptr) {}
 *     ListNode23(int x, ListNode23 *next) : val(x), next(next) {}
 * };
 */
struct ListNode23 {
    int val;
    ListNode23 *next;
    ListNode23() : val(0), next(nullptr) {}
    ListNode23(int x) : val(x), next(nullptr) {}
    ListNode23(int x, ListNode23 *next) : val(x), next(next) {}
};
 class S23 {
    public:
        static bool comp(pair<int, ListNode23*> & a, pair<int, ListNode23*> & b)
        {
            return a.second->val > b.second->val;
        }

        ListNode23* mergeKLists(vector<ListNode23*>& lists) {
            priority_queue<pair<int, ListNode23*>, vector<pair<int, ListNode23*>>, decltype(&comp)> q(comp);
            int m = lists.size();
            if (m == 0) return NULL;
            ListNode23* t; ListNode23* first = t;
            for (int i = 0; i < m; i++)
            {
                if (lists[i] != NULL) {q.emplace(i, lists[i]); lists[i] = lists[i]->next;}
            }
            while (!q.empty())
            {
                int an = q.top().first;
                t->next = q.top().second;
                q.pop();
                if (lists[an]!=NULL)
                {
                    q.emplace(an, lists[an]);
                    lists[an] = lists[an]->next;
                }
                t = t->next;
            }
            return first->next;
        }

        void test() {
            vector<ListNode23*> lists;
            lists.push_back(new ListNode23(1, new ListNode23(4, new ListNode23(5))));
            lists.push_back(new ListNode23(1, new ListNode23(3, new ListNode23(4))));
            lists.push_back(new ListNode23(2, new ListNode23(6)));
            ListNode23* ans = mergeKLists(lists);
            while (ans!=NULL) {
                cout << ans->val << endl;
                ans = ans->next;
            }
            return ;
        }
    };
