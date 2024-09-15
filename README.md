# starter-c
a tamper of c

## 树型结构

### 树和森林的转换
二叉树和树、森林之间是可以相互转换的。

树转换为一棵二叉树:

最左边孩子结点 -> 左子树结点
兄弟结点 -> 作为左边兄弟结点的右子树结点

森林转换为一棵二叉树:

将森林中所有树转化为二叉树，再依次从根结点的右边开始连接
我们发现，相比树转换为二叉树，森林转换为二叉树之后，根节点就存在右子树了，右子树连接的都是森林中其他的树。

### 二叉树的性质
五个性质

1. 第i层最大结点数量 2^(i-1)
2. 深度k的树最大结点数量 n = 2^k - 1，边数E = n - 1
3. n0 = n2 + 1
4. n个结点的完全二叉树的深度k = [logn] + 1 （[logn]是以2为底求n的对数，并向下取整）
5. 对于一颗有n个结点的完全二叉树对于任意结点i
    - 如果有左右孩子，左孩子是2i，右孩子是2i+1
    - 如果i=1则是根结点；如果i>1，其父结点是[i/2]
    - 如果2i>n，则结点i没有左孩子
    - 如果2i+1>n，则结点i没有右孩子

### 红黑树的规则
1. 每个结点可以是黑色或是红色
2. 根结点一定是黑色
3. 红色结点的父结点和子结点不能为红色，也就是说不能有两个连续的红色
4. 所有空结点都是黑色（红黑树将空结点视为叶子结点）
5. 每个结点到空结点路径上出现的黑色结点个数都相等

插入时的判断：（插入时默认以红色结点插入）
- 如果整棵树为NULL，直接作为根结点，变成黑色。
- 如果父结点是黑色，直接插入就完事。
- 如果父结点为红色，且父结点的兄弟结点也是红色，直接变色即可（但是注意得继续往上看有没有破坏之前的结构）
- 如果父结点为红色，但父结点的兄弟结点为黑色，需要先根据情况（LL、RR、LR、RL）进行旋转，然后再变色。