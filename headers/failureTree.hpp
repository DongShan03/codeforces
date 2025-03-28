const int maxn = 100, inf = 0x3f3f3f3f;

class SegTreeNode
{
public:
    int begin,end,val;
};

class segTree
{
public:
    int build_count = 0;
    SegTreeNode interTree[maxn<<2];
    int a[21] = {-1, 7,49,38, 65 ,97, 76, 13, 27, 48,56,120, 466 ,445, 7878, 11854, 144, 134,497,3465, 4568};
    int build(int begin, int end, int i);
    int updata(int begin, int end, int i);
    void loserSort(int n);
    void test();
};

int segTree::build(int begin, int end, int i) // 返回的是以segTree[i]为根的子树的胜者编号，即每次递归做的事情其实是记录败者、返回胜者
{
	interTree[i].begin = begin, interTree[i].end = end;
	if (begin==end)
	{
		return interTree[i].val = begin; // 单点既是胜者又是败者,所以既记录又返回
	}
	int mid = (begin+end)>>1;
	int lwin = build(begin, mid, i<<1); // 左边的胜者
	int rwin = build(mid+1, end, i<<1|1); // 右边的胜者
	interTree[i].val = a[lwin] > a[rwin]?lwin:rwin; // 但是节点只记录败者(数大者为败)
    build_count++;
	return lwin+rwin-interTree[i].val; // 返回胜者
}

int segTree::updata(int begin, int end, int i) // 返回胜者索引
{
	if (interTree[i].begin==begin && interTree[i].end == end)
	{
		return interTree[i].val = begin;
	}
	int mid = (interTree[i].begin+interTree[i].end)>>1, win;
	if (end<=mid)
	{
		win = updata(begin, end, i<<1);
	}
	else if (begin>mid)
	{
		win = updata(begin, end, i<<1|1);
	} // 因为是单点(begin=end), 不可能出现mid介于[begin,end]之间的情况,这体现了更新时败者树不需要与兄弟节点而只需要和父节点比较的特点
	if (a[interTree[i].val]>a[win]) // 如果败者依旧是当前节点的话,则当前节点不必变动,直接送win晋级即可
	{
		return win;
	}
	int ans = interTree[i].val; // 否则要变动了
	interTree[i].val = win; // 更新当前节点
	return ans; // 返回胜者
}

void segTree::loserSort(int n) // 对 a[1,...,n]进行败者树排序
{
	int win = build(1,n,1); // 建树
    cout << "build count: " << build_count << endl;
	while(n--)
	{
		printf("%d ", a[win]);
		a[win] = inf;
		win = updata(win, win,1);
	}
}

void segTree::test()
{
    loserSort(20);
    return ;
}
