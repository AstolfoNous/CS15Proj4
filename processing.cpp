#include "processing.h"
#include "FSTree.h"
#include "DirNode.h"
#include <iostream>
#include <string>

using namespace std;

void traverseNode(DirNode *node, string path){
    for(int i = 0; i < node->numFiles(); i++){
        cout << path << "/" << node->getFile(i) << endl;
    }
    for(int i = 0; i < node->numSubDirs(); i++){
        DirNode *subDir = node->getSubDir(i);
        string subDirName = subDir->getName();
        traverseNode(subDir, path + "/" + subDirName);
    }
}

void traverseDirectory(string directory){
    FSTree fsTree(directory);
    DirNode *root = fsTree.getRoot();
    if (fsTree.isEmpty()) {
        return;
    }
    string path = root->getName();
    traverseNode(root, path);
}