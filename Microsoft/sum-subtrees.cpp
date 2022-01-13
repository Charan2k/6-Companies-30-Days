#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    Node* root = newNode(stoi(ip[0]));
        
    queue<Node*> queue;
    queue.push(root);
        
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        Node* currNode = queue.front();
        queue.pop();
            
        string currVal = ip[i];
        if(currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

int countSubtreesWithSumX(Node* root, int x);

int main()
{
  int t;
  cin>>t;
  getchar();
  while (t--)
  {
     string s;
     getline(cin,s);
     Node* root = buildTree(s);
     
     int x;
     cin>>x;
     getchar();
     cout << countSubtreesWithSumX(root, x)<<endl;
  }
  return 0;
}

int solve(Node* root, int X, int& count){
    if(!root) return 0;
    int sum = root->data;
    if(root->left){
        int ls = solve(root->left, X, count);
        sum += ls;
    }
    if(root->right){
        int rs = solve(root->right, X, count);
        sum += rs;
    }
    if(sum == X){
        count++;
    }
    return sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
	int count = 0;
	solve(root, X, count);
	return count;
}
