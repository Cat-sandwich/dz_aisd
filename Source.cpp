#include <stdio.h>

struct T
{
	double data;
	T* left;
	T* right;
	T(double data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

void func(T* root, int n, int data_l, int data_r)
{
	int n_l = n / 2, n_r = n - n_l -1;
	if (!root)
	{
		root = new T(1);
	}
	T* tmp = root;
	if (n_l != 0)
	{
		tmp->left = new T(data_l);
		func(tmp->left, n_l, data_l + 1, data_r );
	}
	if (n_r != 0)
	{
		tmp->right = new T(data_r);
		func(tmp->right,n_r, data_l , data_r + 1);
	}


}
void print(T* root)
{
	if (root)
	{
		printf("%d\n", int(root->data));
		print(root->left);
		print(root->right);
		
	}
}
int main()
{
	printf("");
	T* root = new T(1);
	func(root, 10, 2, 5);
	print(root);
	getchar();
	return 0;
}