/*
  author: Taj Maun Kamal
  Hackerrank : _maun
*/
#include <iostream>
#include <vector>

enum Color {
    RED, GREEN
};

class Tree;
class TreeNode;
class TreeLeaf;

class TreeVis {
public:
    virtual int getResult() = 0;
    virtual void visitNode(TreeNode*) = 0;
    virtual void visitLeaf(TreeLeaf*) = 0;
};

class Tree {
    int value;
    Color color;
    int depth;

public:
    Tree(int value, Color color, int depth) : value(value), color(color), depth(depth) {}
    int getValue() {
        return value;
    }
    Color getColor() {
        return color;
    }
    int getDepth() {
        return depth;
    }
    virtual void accept(TreeVis& visitor) = 0;
};

class TreeNode : public Tree {
    std::vector<Tree*> children;

public:
    TreeNode(int value, Color color, int depth) : Tree(value, color, depth) {}
    void accept(TreeVis& visitor) {
        visitor.visitNode(this);

        for(int i = 0; i < children.size(); ++i) {
            children[i]->accept(visitor);
        }
    }
    void addChild(Tree* child) {
        children.push_back(child);
    }
};

class TreeLeaf : public Tree {

public:
    TreeLeaf(int value, Color color, int depth) : Tree(value, color, depth) {}
    void accept(TreeVis& visitor) {
        visitor.visitLeaf(this);
    }
};
using namespace std;
int mp[100001];
vector<TreeNode*>xp;
TreeNode *t[100001];
int fc=0;
vector<int>v[100001];
int dep[100001],visited[100001];
int arr[100001],ct[100001];
int n;
long long hp=1,tc=0;
long long mod=1e9 + 7;
class SumInLeavesVisitor : public TreeVis
{
    int s=0;
public:
    int getResult()
    {
        //implement this
        // visitNode(t[1]);

        TreeLeaf* leaf;
        visitLeaf(leaf);

        return s;
    }
    void visitNode(TreeNode* node)
    {
        if(node == NULL)
            return;
      //  cout<<"yes"<<endl;
        //implement this

    }

    void visitLeaf(TreeLeaf* leaf)
    {
        //cout<<"No"<<endl;
        //implement this0
        for(int i=0; i<xp.size(); i++)
        {
                s+=xp[i]->getValue();

        }

    }
};


class ProductOfRedNodesVisitor : public TreeVis
{
    long long s,cp=hp;
public:
    int getResult()
    {
        //implement this
        //visitNode(t[1]);
        return cp;

    }

    void visitNode(TreeNode* node)
    {
        //implement this
        //cout<<"yes"<<endl;
        if(node==NULL)
            return;

        // dp--;
        //cout<<dp<<" "<<node->getValue()<<endl;
        // TreeVis &vi = new SumInLeavesVisitor;
        //cout<<"yes"<<endl;
        // node->accept(*this);


        if(node->getColor()==RED)
            s = ( s * node->getValue())%mod;
    }

    void visitLeaf(TreeLeaf* leaf)
    {
        //implement thi
    }

};

class FancyVisitor : public TreeVis
{
    int s=tc,d=0,st;
public:
    int getResult()
    {
        //implement this
        s -=fc;


        TreeLeaf* leaf;
        visitLeaf(leaf);
        return s - d >=0 ? s - d : (-1)*(s-d);

    }

    void visitNode(TreeNode* node)
    {
        if(node==NULL)
            return;
        st+= node->getDepth() % 2 == 0 ? node->getValue() : 0;
        //implement this
    }

    void visitLeaf(TreeLeaf* leaf)
    {
         for(int i=0; i<xp.size(); i++)
        {
                d+= xp[i]->getColor() == GREEN ? xp[i]->getValue() : 0;;

        }

        //implement this
    }
};
void dfs(int s,int h)
{
    if(!ct[s])
    {
       // cout<<"aa "<<s<<" "<<ct[s]<<" "<<arr[s]<<endl;
        hp= (hp * arr[s])%mod;
        //cout<<hp<<endl;
    }
    if(v[s].size()==1)
        mp[s]++;
    visited[s]=1;
    dep[s]=h;
     tc += dep[s] % 2 == 0 ? arr[s] : 0;
    for(int c:v[s])
      if(!visited[c])
          dfs(c,h + 1);
    return;
}
Tree* solve()
{

    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    for(int i=1; i<=n; i++)
    {
        cin>>ct[i];
        /*if(!ct[i])
            ct[i]=1;
        else
            ct[i]==2;*/
    }


    vector<pair<int,int>>pp;
    for(int i=1; i<=n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        // t[a]->addChild(t[b]);
        v[a].push_back(b);
        v[b].push_back(a);
        pp.push_back({a,b});
        //t[b]->addChild(t[a]);
    }
    dfs(1,0);
    /*for(int i=1; i<=n; i++)
    {
        cout<<dep[i]<<" "<<mp[i]<<endl;
    }*/
   // cout<<hp<<endl;
    for(int i=1; i<=n; i++)
    {
        Color d;
        if(!ct[i])
            d=RED;
        else
            d=GREEN;
        t[i] = new TreeNode(arr[i],d,dep[i]);
      if(mp[i])
      {
        if(dep[i]%2==0)
            fc+=arr[i];
        TreeNode *x = new TreeNode(arr[i],d,dep[i]);
        xp.push_back(x);
      }
    }
    for(int i=0; i<pp.size(); i++)
    {
        t[pp[i].first]->addChild(t[pp[i].second]);
       // t[pp[i].second]->addChild(t[pp[i].first]);
    }
    // t[1].accept =
    return t[1];
}
int main() {
    Tree* root = solve();
	SumInLeavesVisitor vis1 = SumInLeavesVisitor();
    ProductOfRedNodesVisitor vis2 = ProductOfRedNodesVisitor();
    FancyVisitor vis3 = FancyVisitor();

    root->accept(vis1);
    root->accept(vis2);
    root->accept(vis3);

    int res1 = vis1.getResult();
    int res2 = vis2.getResult();
    int res3 = vis3.getResult();

    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;
    std::cout << res3 << std::endl;

    return 0;
}

