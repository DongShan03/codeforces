enum aStarNodeType
{
    Walk, Stop,
};

typedef pair<int, int> pos;
class aStarNode
{
    public:
        int x, y;
        aStarNodeType type;
        aStarNode *parent;
        aStarNode(int x, int y, aStarNodeType type = Walk, aStarNode *parent = nullptr) : x(x), y(y), type(type), parent(parent) {}
};

class aStarManager
{
    private:
        static aStarManager* Instance;
        int mapW, mapH;
        vector<vector<aStarNode*>> mapNodes;
        list<aStarNode> openList;
        list<aStarNode> closeList;
        bool isInternal(pos pos1) {
            if(pos1.first < 0 || pos1.first >= mapW || pos1.second < 0 || pos1.second >= mapH) return false;
            return true;
        }
    public:
        static aStarManager* getInstance()
        {
            if (Instance == nullptr) Instance = new aStarManager();
            return Instance;
        }
        void Initmap(int w, int h)
        {
            mapNodes.resize(w);
            for (int i = 0; i < w; i++) mapNodes[i].resize(h);
            mapW = w; mapH = h;
            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < h; j++)
                {
                    mapNodes[i][j] = new aStarNode(i, j, aStarNodeType::Walk);
                }
            }
            openList.clear();
            closeList.clear();
        }

        void findPath(pos source, pos goal)
        {
            openList.clear();
            closeList.clear();
            if (!isInternal(source) || !isInternal(goal))
            {
                cout << "The position of source or goal is wrong!" << endl;
                return;
            }
            int sx = source.first, sy = source.second, ex = goal.first, ey = goal.second;
            aStarNode* startNode = mapNodes[sx][sy];
            aStarNode* endNode = mapNodes[ex][ey];
            if (startNode->type == aStarNodeType::Stop || endNode->type == aStarNodeType::Stop)
            {
                cout << "The type of start or end is stop!" << endl;
                return;
            }
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (i == 0 && j == 0) continue;
                    int cx = sx + i, cy = sy + j;
                    if(!isInternal(pos(cx, cy))) continue;
                    aStarNode* cursor = mapNodes[cx][cy];
                    if(cursor->type==aStarNodeType::Stop) continue;
                    cursor->parent = startNode;

                }
            }
        }


};
