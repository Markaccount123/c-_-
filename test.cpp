
//第二种方式就是先找到每个结点的路径，然后让路径长的先走他们之间的差距步，然后在找他们最近的公共结点，此时的时间复杂度就是O(3*N) ~ 就是O(N)次
class Solution {
public:
	//前序遍历找路径
	//在树中找到根到x的路径
	bool FindPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
	{
		if (root == nullptr)
			return false;


		path.push(root);
		if (root == x)
			return true;


		if (FindPath(root->left, x, path))
			return true;
		if (FindPath(root->right, x, path))
			return true;
		//root左树，root右树，都没有x节点,但是你已经把该节点压入了栈中，所以还需要pop掉它，因为他不是路径上的一个节点
		//说明root不会是路径中的一个节点，所以弹出
		path.pop();
		//如果下面这句理解不了，可以思考找4的时候，把6压入栈的情况，此时6也应该给5返回一个false
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//仔细考虑一下为什么这里要使用栈，那是用到了，后进先出的特性，当不满足情况的时候，就考虑拿该结点从栈中pop掉
		stack<TreeNode*> pPath;
		stack<TreeNode*> qPath;
		FindPath(root, p, pPath);
		FindPath(root, q, qPath);
		//此时在两个栈中中就已经分别保存了该结点路径上的所有结点
		//先让长的走差距步
		while (pPath.size() > qPath.size())
		{
			pPath.pop();
		}


		while (pPath.size() < qPath.size())
		{
			qPath.pop();
		}
		//到这里说明，此时两个路径一样长了
		while (pPath.top() != qPath.top())
		{
			pPath.pop();
			qPath.pop();
		}
		//此时返回的就是最近的公共结点
		return qPath.top();
	}
};


class Solution {
public:
	bool TreeFind(TreeNode* root, TreeNode* x)
	{
		if (root == nullptr)
			return false;
		if (root == x)
			return true;

		//你会发现思路在一步的时候是有可能卡住的，你仔细想一下//那么下边已经把根的情况都考虑完了，剩下的不就应该是在左树中或者右树中了吗？并且我只是想要知道这个结点在不在这里面，不要得到它的结点
		return TreeFind(root->left, x) || TreeFind(root->right, x);
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr)
			return nullptr;
		//整个考虑完了以后就会发现，其实还漏了一种情况，比如说5和4的公共结点，那么这个公共结点就是5if(p == root  || q == root)
		{
			return root;
		}
		bool pInLeft, pInRight, qInLeft, qInRight;
		//且p、q结点均在二叉树中
		pInLeft = TreeFind(root->left, p);
		pInRight = !pInLeft; //在左边了，肯定不会在右边了，否则情况相反

		qInLeft = TreeFind(root->left, q);
		qInRight = !qInLeft;

		//一个在左树，一个在右树的时候，就不用考虑了，此时根结点就是他们的公共结点if((pInLeft && qInRight) || (pInRight && qInLeft))
		return root;
		else if (pInLeft && qInLeft)
			return lowestCommonAncestor(root->left, p, q);
		else
			return lowestCommonAncestor(root->right, p, q);
	}
};
