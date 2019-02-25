//
//  Tree.hpp
//  1-1链表
//
//  Created by wangjianlong on 2019/2/22.
//  Copyright © 2019 JL.Com. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp
#include "Config.h"
/*树
 是n（n>=0）个结点的有限集。
 n=0时，为空树；
 任意一棵非空树中：（1）有且仅有一个特定的称为根的结点。（2）当n>1时，其余结点可分为m（m>0）个互不相交的有限集。其中每一个集合本身又是一棵树，并称为根的子树。
 
 树的结点包含一个数据元素及其若干指向子树的分支。
 
 结点拥有的子树称为结点的度。度为0的结点称为叶结点或终端结点；度不为0的结点称为非终端结点或分支结点。除根结点外，分支结点，也成为内部结点；
 
 树的度是树内各结点的度的最大值。
 
 结点的子树的根称为该结点的孩子。相应地，该结点称为孩子的双亲。
 
 结点的层次从根开始定义起，根为第一层，根的孩子为第二层。。。树中结点的最大层次称为树的深度或高度。
 
 如果将树中结点的各个子树看成从左至右是有次序的，不能互换的，则称为该树为有序树，否则称为无序树。
 
 森林是m（m>0）棵互不相交的树的集合。对树中每个结点而言，其子树的集合即为森林。
 
 
 树的存储结构：双亲表示法，孩子表示法，孩子兄弟表示法。
 
 
 */
#include <stdio.h>

// 双亲表示法：除了根结点外，其余每个结点，它不一定有孩子，但是一定有且仅有一个双亲。
/**
 结点结构
 */
typedef struct {
    //结点数据
    int value;
    //双亲位置
    int parent;
} PTNode;

typedef struct {
    //结点数组
    PTNode nodes[MAXSIZE];
    //根的位置和结点数
    int r,n;
}PTree;

// 孩子表示法：把每个结点的孩子结点排列起来，以单链表作存储结构，则n个结点有n个孩子链表，如果是叶子结点则此单链表为空。然后n个头指针又组成一个线性表，采用顺序存储结构，存进一个一维数组中。


/**
 孩子结点
 */
typedef struct CTNode{
    int child;
    struct CTNode *next;
} *childPtr;


/**
 表头结构
 */
typedef struct {
    int data;
    //定义此结点双亲结点的索引位置。
    int parentIndex;
    childPtr firstChild;
}CTBox;


/**
 树结构
 */
typedef struct {
    //结点数组
    CTBox nodes[MAXSIZE];
    //根的位置和结点数
    int r,n;
}CTree;

// 这样的结构对于查找某个结点的某个孩子，或者找到某个结点的兄弟，只需要查找这个结点的孩子单链表即可。对于遍历整棵树也是很方便的，对头结点的数组循环即可。 如果知道某个结点的双亲？需要遍历整棵树才行。

//////////////////////////孩子兄弟表示法///////////////////

typedef struct CSNode{
    int data;
    struct CSNode *firstChild,*rightSib;
}CSNode,*CSTree;

//这种表示方式的缺陷就是找某个结点的双亲，比较麻烦。




//////////////////////////二叉树///////////////////
/*
 特点：
 1，每个结点最多有两棵子树
 2.左子树和右子树是有顺序的，次序不能任意颠倒
 3.即使树中某结点只有一棵子树，也要区分它是左子树还是右子树
 
 五中基本形态：
 1.空二叉树2.只有一个根结点。3根结点只有左子树。4.根结点只有右子树。5.根结点既有左子树又有右子树
 
 特殊的二叉树：
 1.斜树 都有的结点都在左子树的二叉树叫左斜树。所有结点都是只有右子树的二叉树叫右斜树，统称斜树。
        线性表就是一个极其特殊的表现形式。
 
 2.满二叉树  （1）：叶子只能出现在最下一层。（2）非叶子结点的度一定是2.（3）在同样深度的二叉树中，满二叉树的结点个数最多，叶子树最多。
    如果所有分支结点都存在左子树和右子树，并且所有叶子都在同一层上。
 3.完全二叉树
 对一棵具有n个结点的二叉树按层序编号，如果编号对i的结点与同样深度的满二叉树中编号为i的结点在二叉树中位置完全相同，则这棵二叉树称为完全二叉树。
 
 满二叉树一定是一棵完全二叉树，但完全二叉树不一定是满的。
 完全二叉树的特点：（1）叶子结点只能出现在最下两层（2）最下层的叶子一定集中在左部连续位置（3）倒数二层，若有叶子结点，一定都在右部连续位置（4）如果结点度为1，则该结点只有左孩子，即不存在只有右子树的情况。（5）同样结点数的二叉树，完全二叉树的深度最小
 
 二叉树性质：
 （1）第i层上至多有2^(i-1)个结点
 （2）深度为k的二叉树至多有2^(k) - 1 个结点 k>=1
 （3）对任何一棵二叉树T，如果其终端结点数为n0，度为2的结点数为n2.则n0 = n2 +1
 （4）具有n个结点的完全二叉树的深度为 |log2^（n+1）|
 （5）如果对一棵有n个结点的完全二叉树的结点按层序编号，从上到下，从左到右、则对任一结点i有：
      <1>如果i=1，则结点i是二叉树的根，无双亲；如果i>1，则其双亲是结点。
      <2>如果2i>n,则结点i无左孩子；否则其左孩子是结点2i
      <3>如果2i+1>n,则结点i无右孩子；否则其右孩子是结点2i+1;
 */
//二叉链表

//结点结构
typedef struct BiTNode{
    //结点数据
    char data;
    //左右孩子指针
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//如果有需要，还可以再增加一个指向双亲的指针域，那样就称为三叉链表

//二叉树遍历方法
/*
 1.前序遍历 ：若二叉树为空，则空操作返回，否则先访问根结点，然后前序遍历左子树，再前序遍历右子树。
 2.中序遍历：若树为空，则空操作返回，否则从根结点开始（注意并不是先访问根结点），中序遍历根结点的左子树，然后是访问根结点，最后中序遍历右子树。
 3.后序遍历：若树为空，则空操作返回。否则从左到右先叶子后结点的方式遍历访问左右子树，最后是访问根结点。
 4.层序遍历：若树为空，则空操作返回。否则从树的第一层，也就是根结点开始访问，从上而下逐层遍历，在同一层中，按从左到右的顺序对结点逐个访问。
 */

//前序遍历
void preOrderTraverse(BiTree T);
//中序遍历
void inOrderTraverse(BiTree T);
//后序遍历
void PostOrderTraverse(BiTree T);

//已知前序遍历序列和中序遍历序列，可以唯一确定一棵二叉树
//已知后序遍历序列和中序遍历序列，可以唯一确定一棵二叉树

//前序创建二叉树
void creatBigTree(BiTree *T);

#endif /* Tree_hpp */
