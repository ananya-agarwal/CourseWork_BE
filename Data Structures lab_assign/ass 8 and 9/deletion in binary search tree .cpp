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
node* deletion(node* root,int p)
{
   if(root==NULL)
   {
   	  return NULL;
   }
   else if(p<root->data)
   {
   	  root->left=deletion(root->left,p);
   	  return root;
   }
   else if( root->data==p)
   {
   	    if(root->left==NULL && root->right==NULL)
   	    {
   	    	delete root;
   	    	return NULL;
		}
		if(root->left!=NULL && root->right==NULL)
		{
			node* temp=root->left;
			delete root;
			return temp;
		}
		if(root->left==NULL && root->right!=NULL)
		{
			node* temp=root->right;
			delete root;
			return temp;
		}
		if(root->left!=NULL && root->right!=NULL)
		{
			node* replace=root->right;
			while(replace->left!=NULL)
			{
				replace=replace->left;
			}
			root->data=replace->data;
			root->right=deletion(root->right,replace->data);
			return root;
	    }
   }
   else
   {
   	  root->right=deletion(root->right,p);
   	  return root;
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
	int s;
	cin>>s;
	node* d=deletion(root,s);
	bfs(d);
	return 0;
}
