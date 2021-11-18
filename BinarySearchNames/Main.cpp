#include <iostream>
#include <fstream>
//#include <ostream>
#include <istream>
#include "BinarySearchTree.h"
#include "BinaryNodeTree.h"
#include "BinaryNode.h"

using namespace std;


/// <summary>
/// Read through and print out string
/// </summary>
/// <param name="s"></param>
void PrintIN(string& s)
{
	cout << s << endl;
}

/// <summary>
/// Opening file in "append" mode, so it doesn't delete the previous contents of the file
/// The file written to is called TreeToFile.txt
/// The log() function helps with the appending. Parameter ios_base::seek to the end of stream before each write
/// Parameter ios_base::app mean open for writing
/// </summary>
/// <param name="s"></param> s is string that is read
void TreeToFile(string& s)
{
	string filename = "TreeToFile.txt";
	ofstream log(filename, ios_base::app | ios_base::out);
	log << s + "\n";
}

/// <summary>
/// Opening file in "append" mode, so it doesn't delete the previous contents of the file
/// The file written to is called DummyNodeToFile.txt
/// The log() function helps with the appending. Parameter ios_base::seek to the end of stream before each write
/// Parameter ios_base::app mean open for writing
/// </summary>
/// <param name="s"></param> s is string that is read
void DummyNodeToFile(string& s)
{
	string filename = "DummyNodeToFile.txt";
	ofstream log(filename, ios_base::app | ios_base::out);
	log << s + "\n";
}

int main()
{
	string filename = "Names.txt";
	BinarySearchTree<string> aTree;
	ofstream file(filename);
	string name;

	// 1. Put the names that follow into a file
	if (file.is_open())
	{
		file << "George\n";
		file << "Bill\n";
		file << "Nancy\n";
		file << "Antonio\n";
		file << "Sally\n";
		file << "Mike\n";
		file << "Cathy\n";
		file << "Zac\n";
		file << "Nolan\n";
		file << "Kody\n";
		file << "Xena\n";
		file << "Yate\n";
	}
	file.close();

	// 2. Read the file and insert the names into the binary search tree
	ifstream file1(filename);
	if (file1.is_open())
	{
		while (getline(file1, name))
		{
			cout << name << endl;
			aTree.add(name);

		}
	} 
	file1.close();

	// 3. After all nodes have been read, print the tree using inorder.
	cout << "\nTree using inorder" << endl;
	aTree.inorderTraverse(PrintIN);
	
	// 4. Print the height of the tree
	cout << endl;
	cout << "Tree height : " << aTree.getHeight() << endl;

	// 5. Remove Yate and Nancy
	aTree.remove("Yate");
	aTree.remove("Nancy");
	cout << "\nYate and Nancy have been removed.\n" << endl;

	// 6. Print the height of the tree
	cout << "Tree height : " << aTree.getHeight() << endl;

	// 7. Print the tree using inorder
	cout << "\nTree using inorder" << endl;
	aTree.inorderTraverse(PrintIN);

	// 8. write the contents of the tree to a file, inorder,
	//    then read it back in to balance the tree 
	aTree.inorderTraverse(TreeToFile);
	string filename2 = "TreeToFile.txt";
	ifstream file3(filename2);
	BinaryNodeTree<string> bTree;
	int tildeNumber = 0;

	// Reading contents of file TreeToFile.txt and adding to Tree
	if (file3.is_open())
	{
		cout << endl;
		while (getline(file3, name))
		{
			cout << name << endl;
			bTree.add(name);
		}
		// A full tree has the number of nodes of 2^h – 1
		int balancedTreeNodeCount = pow(2,bTree.getHeight()) - 1;

		// Number assigned to dummy node increments when added
		while (bTree.getNumberOfNodes() < balancedTreeNodeCount)
		{
			// Adding a tilde(~) and a number
			bTree.add("~" + to_string(tildeNumber));
			// increment tildeNumber when assigned
			tildeNumber++;
		}
	}
	
	// Writing Tree with dummy nodes to file
	bTree.inorderTraverse(DummyNodeToFile);

	// Reading the Tree with dummy nodes then removing dummy nodes
	string filename3 = "DummyNodeToFile.txt";
	ifstream file4(filename3);
	
	// Open DummyNodeToFile.txt and read through it
	if (file4.is_open())
	{ 
		cout << endl;
		while (getline(file4, name))
		{
			cout << name << endl;
			// search for string that starts with tilde(~) and remove from
			// Tree
			if (name.find('~') != string::npos)
			{
				bTree.remove(name);
			}
		}
	}
	// Print out the number of dummy nodes
	cout << "\nThe number of dummy nodes is " << tildeNumber << endl;
}