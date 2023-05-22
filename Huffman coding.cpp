#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int fre;
	char ch;
	Node *left,*right;
	Node(int f,char c,Node *l,Node *r)
	{
		this->fre=f;
		this->ch=c;
		this->left=l;
		this->right=r;
	}
};
struct mycomp
{
	bool operator()(Node *a,Node *b)
	{
		 return a->fre>b->fre;
	} 
};

void printCodes(Node *root,string s)
{
	if(root==NULL)
	  return;
	if(root->ch!='$')
	{
		cout<<root->ch<<" "<<s<<endl;
		return;
	}
	printCodes(root->left,s+"0");
	printCodes(root->right,s+"1");
}
void Huffman(char a[],int freq[],int n)
{
	priority_queue<Node *,vector<Node *>,mycomp>pq;
	for(int i=0;i<n;i++)
	{
		pq.push(new Node(freq[i],a[i],NULL,NULL));
	}
	while(pq.size()>1)
	{
		Node *lt=pq.top();
		pq.pop();
		Node *rt=pq.top();
		pq.pop();
		Node *node=new Node(lt->fre+rt->fre,'$',lt,rt);
		pq.push(node);
	}
	printCodes(pq.top(),"");
	pq.pop();
}
int main()
{
	char a[]={'a','d','b','e','f'};
	int freq[]={10,50,20,40,80};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The huffman code for the character is as follows\n";
	Huffman(a,freq,n);
	return 0;
}

// time complexity= O(nlog(n))

// space complexity=O(n)
