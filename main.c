#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE (26) 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 


struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE];
	bool isWordEnd; 
}; 

struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = (struct TrieNode*)malloc(sizeof(struct TrieNode)); 
	pNode->isWordEnd = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 

void insert(struct TrieNode *root, const char key[30]) 
{ 
	struct TrieNode *temp = root; 

	for (int level = 0; level < strlen(key); level++) 
	{ 
		int index = CHAR_TO_INDEX(key[level]); 
		if (!temp->children[index]) 
			temp->children[index] = getNode(); 

		temp = temp->children[index]; 
	} 

	temp->isWordEnd = true; 
} 

int main() 
{ 

	FILE *fp,*fp2;char word[30];
	fp=fopen("dict.txt","r");
	fp2=fopen("res.txt","w");
	struct TrieNode* root = getNode(); 

	while(!feof(fp))
	{
		fscanf(fp,"%s",word);
		insert(root,word);
		fprintf(fp2,"%s\n",word);
	}
	

	return 0; 
} 
