#include <iostream>
#include<ctype.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
	int element;
	node* left;
	node* right;
	int height;
};
typedef struct node* nodeptr;
class bstree
{
public:
	void insert(int, nodeptr&);
	void del(int, nodeptr&);
	int deletemin(nodeptr&);
	void find(int, nodeptr&);
	nodeptr findmin(nodeptr);
	nodeptr findmax(nodeptr);
	void makeempty(nodeptr&);
	void copy(nodeptr&, nodeptr&);
	nodeptr nodecopy(nodeptr&);
	void preorder(nodeptr);
	void inorder(nodeptr);
	void postorder(nodeptr);
	int bsheight(nodeptr);
	nodeptr srl(nodeptr&);
	nodeptr drl(nodeptr&);
	nodeptr srr(nodeptr&);
	nodeptr drr(nodeptr&);
	int max(int, int);
	int nonodes(nodeptr);
};
// Inserting a node
void bstree::insert(int x, nodeptr& p)
{
	if (p == NULL)
	{
		p = new node;
		p->element = x;
		p->left = NULL;
		p->right = NULL;
		p->height = 0;
		if (p == NULL)
		{
			std::cout << "Out of Space\n" << std::endl;
		}
	}
	else
	{
		if (x < p->element)
		{
			insert(x, p->left);
			if ((bsheight(p->left) - bsheight(p->right)) == 2)
			{
				if (x < p->left->element)
				{
					p = srl(p);
				}
				else
				{
					p = drl(p);
				}
			}
		}
		else if (x > p->element)
		{
			insert(x, p->right);
			if ((bsheight(p->right) - bsheight(p->left)) == 2)
			{
				if (x > p->right->element)
				{
					p = srr(p);
				}
				else
				{
					p = drr(p);
				}
			}
		}
		else
		{
			std::cout << "Element exists\n" << std::endl;
		}
	}
	int m, n, d;
	m = bsheight(p->left);
	n = bsheight(p->right);
	d = max(m, n);
	p->height = d + 1;
}
// Finding the Smallest
nodeptr bstree::findmin(nodeptr p)
{
	if (p == NULL)
	{
		std::cout << "There are no elements in the tree\n" << std::endl;
		return p;
	}
	else
	{
		while (p->left != NULL)
		{
			p = p->left;
			//return p;
		}
		return p;
	}
}
// Finding the Largest node
nodeptr bstree::findmax(nodeptr p)
{
	if (p == NULL)
	{
		std::cout << "There are no elements in the tree\n" << std::endl;
		return p;
	}
	else
	{
		while (p->right != NULL)
		{
			p = p->right;
			//return p;
		}
		return p;
	}
}
// Finding an element
void bstree::find(int x, nodeptr& p)
{
	if (p == NULL)
	{
		std::cout << "Sorry, but there is no such element\n" << std::endl;
	}
	else
	{
		if (x < p->element)
		{
			find(x, p->left);
		}
		else
		{
			if (x > p->element)
			{
				find(x, p->right);
			}
			else
			{
				std::cout << "The element you were looking for is in the tree!\n" << std::endl;
			}
		}
	}
}
// Copy a tree
void bstree::copy(nodeptr& p, nodeptr& p1)
{
	makeempty(p1);
	p1 = nodecopy(p);
}
// Make a tree empty
void bstree::makeempty(nodeptr& p)
{
	nodeptr d;
	if (p != NULL)
	{
		makeempty(p->left);
		makeempty(p->right);
		d = p;
		free(d);
		p = NULL;
	}
}
// Copy the nodes
nodeptr bstree::nodecopy(nodeptr& p)
{
	nodeptr temp;
	if (p == NULL)
	{
		return p;
	}
	else
	{
		temp = new node;
		temp->element = p->element;
		temp->left = nodecopy(p->left);
		temp->right = nodecopy(p->right);
		return temp;
	}
}
// Deleting a node
void bstree::del(int x, nodeptr& p)
{
	nodeptr d;
	if (p == NULL)
	{
		std::cout << "Sorry, but there is no such element\n" << std::endl;
	}
	else if (x < p->element)
	{
		del(x, p->left);
	}
	else if (x > p->element)
	{
		del(x, p->right);
	}
	else if ((p->left == NULL) && (p->right == NULL))
	{
		d = p;
		free(d);
		p = NULL;
		std::cout << "Item removedн\n" << std::endl;
	}
	else if (p->left == NULL)
	{
		d = p;
		free(d);
		p = p->right;
		std::cout << "Item removed\n" << std::endl;
	}
	else if (p->right == NULL)
	{
		d = p;
		p = p->left;
		free(d);
		std::cout << "Item removed\n" << std::endl;
	}
	else
	{
		p->element = deletemin(p->right);
	}
}
int bstree::deletemin(nodeptr& p)
{
	int c;
	std::cout << "Remove minimum value selected\n" << std::endl;
	if (p->left == NULL)
	{
		c = p->element;
		p = p->right;
		return c;
	}
	else
	{
		c = deletemin(p->left);
		return c;
	}
}
void bstree::preorder(nodeptr p)
{
	if (p != NULL)
	{
		std::cout << p->element << "\t";
		preorder(p->left);
		preorder(p->right);
	}
}
// Inorder Printing
void bstree::inorder(nodeptr p)
{
	if (p != NULL)
	{
		inorder(p->left);
		std::cout << p->element << "\t";
		inorder(p->right);
	}
}
// PostOrder Printing
void bstree::postorder(nodeptr p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		std::cout << p->element << "\t";
	}
}
int bstree::max(int value1, int value2)
{
	return ((value1 > value2) ? value1 : value2);
}
int bstree::bsheight(nodeptr p)
{
	int t;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}
nodeptr bstree::srl(nodeptr& p1)
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = max(bsheight(p2->left), p1->height) + 1;
	return p2;
}
nodeptr bstree::srr(nodeptr& p1)
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = max(p1->height, bsheight(p2->right)) + 1;
	return p2;
}
nodeptr bstree::drl(nodeptr& p1)
{
	p1->left = srr(p1->left);
	return srl(p1);
}
nodeptr bstree::drr(nodeptr& p1)
{
	p1->right = srl(p1->right);
	return srr(p1);
}
int bstree::nonodes(nodeptr p)
{
	int count = 0;
	if (p != NULL)
	{
		nonodes(p->left);
		nonodes(p->right);
		count++;
	}
	return count;
}
int main()
{
	//clrscr();
	nodeptr root, root1, min, max;//,flag;
	int a, choice, findele, delele;
	char ch = 'y';
	bstree bst;
	//system("clear");
	root = NULL;
	root1 = NULL;
	std::cout << "\n\t\t\t\tAVL Tree" << std::endl;
	std::cout << "\t\t\t\t:::::::::::::::::::\n" << std::endl;
	do
	{
		std::cout << "\t\t::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
		std::cout << "\t\t::::1 Insert new node::::::::::::::::" << std::endl;
		std::cout << "\t\t::::2 Find the minimum element:::::::::::" << std::endl;
		std::cout << "\t\t::::3 Find the maximum element:::::::::::::::" << std::endl;
		std::cout << "\t\t::::4 Search by value:::::::::::::::::::" << std::endl;
		std::cout << "\t\t::::5 Remove element:::::::::::::::::::" << std::endl;
		std::cout << "\t\t::::6 Workaround Option1:::::::::::::::::" << std::endl;
		std::cout << "\t\t::::7 Workaround Option2::::::::::::::::::" << std::endl;
		std::cout << "\t\t::::8 Workaround Option3::::::::::::::::" << std::endl;
		  std::cout << "\t\t::::9 Show tree height:::" << std::endl;
		std::cout << "\t\t::::0 Exit:::::::::::::::::::::::::::::" << std::endl;
		std::cout << "\t\t::::::::::::::::::::::::::::::::::::::::::::::::\n" << std::endl;
		std::cout << "\nSelect the desired action and click Enter: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "\n\t\tAdding a new node" << std::endl;
			std::cout << "\t\t:::::::::::::\n" << std::endl;
			std::cout << "Enter element: ";
			std::cin >> a;
			bst.insert(a, root);
			std::cout << "\nNew element added successfully\n" << std::endl;
			break;
		case 2:
			if (root != NULL)
			{
				min = bst.findmin(root);
				std::cout << "\nMinimum element in a tree: " << min -> element << std::endl;
			}
			break;
		case 3:
			if (root != NULL)
			{
				max = bst.findmax(root);
				std::cout << "\nMaximum element in the tree: " << max -> element << std::endl;
			}
			break;
		case 4:
			std::cout << "\nEnter the element you are looking for: ";
			std::cin >> findele;
			if (root != NULL)
			{
				bst.find(findele, root);
			}
			break;
		case 5:
			std::cout << "\nWhich node should I delete? : ";
			std::cin >> delele;
			bst.del(delele, root);
			bst.inorder(root);
			std::cout << std::endl;
			break;
		case 6:
			std::cout << "\n\t\tBypass option 1" << std::endl;
			bst.preorder(root);
			std::cout << std::endl;
			break;
		case 7:
			std::cout << "\n\t\tBypass option 2" << std::endl;
			bst.inorder(root);
			std::cout << std::endl;
			break;
		case 8:
			std::cout << "\n\t\tBypass option 3" << std::endl;
			bst.postorder(root);
			std::cout << std::endl;
			break;
		case 9:
			std::cout << "\n\t\tВЫСОТА\n" << std::endl;
			std::cout << "The tree has a height of: " << bst.bsheight(root) << std::endl;
			break;
		case 0:
			std::cout << "\n\tThank you for using the program\n" << std::endl;
			break;
		default:
			std::cout << "Sorry! wrong input\n" << std::endl;
			break;
		}
		system("pause");
		system("cls");
	} while (choice != 0);
	return 0;
}