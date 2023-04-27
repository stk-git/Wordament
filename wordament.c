#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
char path[17];

#define	ALPHABET_SIZE	26
typedef struct tnode TNode;
struct tnode
{
	bool isEOW;
	TNode *next[ALPHABET_SIZE];
}; TNode * root;

TNode *createTrieNode()
{
    TNode *newNode = (TNode*)malloc(sizeof(TNode));
    newNode->isEOW = false;
    int i;
    for(i=0;i<26;i++)
        newNode->next[i] = NULL;
    return newNode;
}

bool insertWordInTrie(TNode *root, char *word)
{
    for(int i=0;word[i];i++)
    {  if(root->next[word[i]-'a']==NULL)
          root->next[word[i]-'a']=createTrieNode();

             root=root->next[word[i]-'a'];
    }
  if(root->isEOW==true)
    return false;
  else{
    root->isEOW=true;
  return true;}

}
bool checkword(TNode *root,char path[])
{

    for(int i=0;path[i];i++)
    {

    if((root->next[tolower(path[i])-'a'])!= NULL )
      root =  root->next[path[i]-'a'];
     else
     return false;
    }


          if(root->isEOW==true)
            return true;
          else
            return false;

}
void generatewords(char a[4][4],int i,int j,int k,bool visited[4][4])
{   if( (i<0) || (j<0) || (i>=4) || (j>=4) || (visited[i][j]== true))
      return ;
      if(visited[i][j]== false)
      {  path[k]= a[i][j];
         path[k+1]= '\0';
          visited[i][j]=true;
          if(checkword(root,path))
          {
           printf("%s",path);
           printf("\n");
          }
      }


    for(int di=-1;di<=1;di++)
    {  for(int dj=-1;dj<=1;dj++)
        {
            generatewords(a,i+di,j+dj,k+1,visited);
        }

    }
    visited[i][j] = false;



}

int main()
{
    char a[4][4]={
                     {'T','O','A','S'},
                    { 'E','S','B','K' },
                    { 'S','E','D','O'},
                    { 'R','P','E','N'}  } ;
    bool visited[4][4];

memset(visited,0,sizeof visited);
 FILE * fp= fopen("C:\\users\\Welcome\\Desktop\\dic.txt","r");

    if(fp==NULL){
        printf("file can not be opened");
        exit(0);
    }     root = createTrieNode();

    char word[100];
    while(!feof(fp))
    {
        fscanf(fp,"%s",word);
        insertWordInTrie(root,word);
    }
    fclose(fp);
    for(int i=0;i<=3;i++)
        for(int j=0;j<=3;j++)
   generatewords(a,i,j,0,visited);
        return 0;
}

