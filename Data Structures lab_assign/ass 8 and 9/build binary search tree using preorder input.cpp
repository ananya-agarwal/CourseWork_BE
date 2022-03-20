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
node* preorder(int pre[], int n)
{
      if(n==0)
      {
      	return NULL;
	  }
	  	node* root=new node(pre[0]);
	  for(int i=1; i<n; i++)
	  {
	  	 root=insertioninBST(root,pre[i]);
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
int main()
{
	int n;
    cin>>n;
    int pre[n];
    for(int i=0; i<n; i++)
    {
        cin>>pre[i];
    }
    node*root=preorder(pre,n);
	bfs(root);
	return 0;
}
	  
