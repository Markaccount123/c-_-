
//�ڶ��ַ�ʽ�������ҵ�ÿ������·����Ȼ����·��������������֮��Ĳ�ಽ��Ȼ��������������Ĺ�����㣬��ʱ��ʱ�临�ӶȾ���O(3*N) ~ ����O(N)��
class Solution {
public:
	//ǰ�������·��
	//�������ҵ�����x��·��
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
		//root������root��������û��x�ڵ�,�������Ѿ��Ѹýڵ�ѹ����ջ�У����Ի���Ҫpop��������Ϊ������·���ϵ�һ���ڵ�
		//˵��root������·���е�һ���ڵ㣬���Ե���
		path.pop();
		//������������ⲻ�ˣ�����˼����4��ʱ�򣬰�6ѹ��ջ���������ʱ6ҲӦ�ø�5����һ��false
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//��ϸ����һ��Ϊʲô����Ҫʹ��ջ�������õ��ˣ�����ȳ������ԣ��������������ʱ�򣬾Ϳ����øý���ջ��pop��
		stack<TreeNode*> pPath;
		stack<TreeNode*> qPath;
		FindPath(root, p, pPath);
		FindPath(root, q, qPath);
		//��ʱ������ջ���о��Ѿ��ֱ𱣴��˸ý��·���ϵ����н��
		//���ó����߲�ಽ
		while (pPath.size() > qPath.size())
		{
			pPath.pop();
		}


		while (pPath.size() < qPath.size())
		{
			qPath.pop();
		}
		//������˵������ʱ����·��һ������
		while (pPath.top() != qPath.top())
		{
			pPath.pop();
			qPath.pop();
		}
		//��ʱ���صľ�������Ĺ������
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

		//��ᷢ��˼·��һ����ʱ�����п��ܿ�ס�ģ�����ϸ��һ��//��ô�±��Ѿ��Ѹ���������������ˣ�ʣ�µĲ���Ӧ�����������л������������𣿲�����ֻ����Ҫ֪���������ڲ��������棬��Ҫ�õ����Ľ��
		return TreeFind(root->left, x) || TreeFind(root->right, x);
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr)
			return nullptr;
		//�������������Ժ�ͻᷢ�֣���ʵ��©��һ�����������˵5��4�Ĺ�����㣬��ô�������������5if(p == root  || q == root)
		{
			return root;
		}
		bool pInLeft, pInRight, qInLeft, qInRight;
		//��p��q�����ڶ�������
		pInLeft = TreeFind(root->left, p);
		pInRight = !pInLeft; //������ˣ��϶��������ұ��ˣ���������෴

		qInLeft = TreeFind(root->left, q);
		qInRight = !qInLeft;

		//һ����������һ����������ʱ�򣬾Ͳ��ÿ����ˣ���ʱ�����������ǵĹ������if((pInLeft && qInRight) || (pInRight && qInLeft))
		return root;
		else if (pInLeft && qInLeft)
			return lowestCommonAncestor(root->left, p, q);
		else
			return lowestCommonAncestor(root->right, p, q);
	}
};
