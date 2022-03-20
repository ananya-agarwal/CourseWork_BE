#include<iostream>
#include<queue>
using namespace std;
class node
{
	public:
		int data;
		node* left;
		node* right;
		node(int d)
		{
			data=d;
			right=NULL;
			left=NULL;
		}
};
node* insertioninBST(node* root, int d)
{
	if(root==NULL)
	{
		return new node(d);
	}
	if(d<root->data)
	{
		root->left=insertioninBST(root->left,d);
	}
	else
	{
		root->right=insertioninBST(root->right,d);
	}
	return root;	
}
void bfs(node* root)
{
    queue<node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node* f=q.front();
		if(f==NULL)
		{
			cout<<endl;
			q.pop();
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
	   else
	   {
	   cout<<f->data<<" ";
	   q.pop();
	   if(f->left)
	   {
	   	  q.push(f->left);
	   }
	   if(f->right)
	   {
	   	  q.push(f->right);
	   } 
       }
	}		

}
node* build()
{
	int d;
	cin>>d;
	node* root=NULL;
	while(d!=-1)
	{
		root=insertioninBST(root,d);
		cin>>d;
	}
	return root;
}
int main()
{
	node* root=build();
	bfs(root);
	return 0;
}
