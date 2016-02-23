/*
 * binary_tree.cpp
 *
 *  Created on: Nov 10, 2015
 *      Author: oagomez
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

struct Node
{
	Node * left;
	Node * right;
	int data;
};

void postorder(Node* p, int indent=0)
{
	if(p != NULL)
	{
		if(p->left) postorder(p->left, indent+4);
		if (indent)
		{
			//for (int i=0; i< indent; i++)
			//	std::cout << " ";
			std::cout << std::setw(indent) << ' ';
		}
		std::cout<< p->data << "\n";
		if(p->right) postorder(p->right, indent+4);


	}
}

Node* create_tree(int nodes)
{
	Node * root = new Node();
	root->data = 0;
	Node * p = root;
	for (int i = 1; i< nodes; i++)
	{
		Node * newNode = new Node();
		newNode->data = i;
		if(p->left == NULL)
		{
			p->left = newNode;
		}
		else if (p->right == NULL)
		{
			p->right = newNode;
		}
		else
		{
			if (i%2 == 0 )
			{
				p = p->left;
				p->left = newNode;
			}
			else
			{
				p = p->right;
				p->right = newNode;
			}


		}
	}
	return root;
}

void print_tree(Node * root)
{
	postorder(root);

}

void usage()
{
	std::cout << "Usage:\n\tbinary_tree <# of nodes>" << std::endl;
}

int main(int argc, const char * argv[])
{
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	if ( argc <=1 )
	{
		usage();
		return 1;
	}
	else
	{
		std::cout << "Generating tree with " << argv[1] << " nodes" << std::endl;
		int nodes = atoi(argv[1]);
		Node * root = create_tree(nodes);
		print_tree(root);

	}

	return 0;
}



