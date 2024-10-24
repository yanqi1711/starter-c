# starter-c
a tamper of c

## 树型结构

### 树和森林的转换
二叉树和树、森林之间是可以相互转换的

树转换为一棵二叉树：

最左边孩子结点 -> 左子树结点
兄弟结点 -> 作为左边兄弟结点的右子树结点

![](/public/tree.png)

森林转换为一棵二叉树：
首先我们还是按照二叉树转换为树的规则，将森林中所有树转换为二叉树，接着我们只需要依次连接即可

![](/public/forest.png)

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

### B树满足条件 m阶

> B树的搜索，顺序访问，插入，删除都是对数阶
> 红黑树的黑色结点个数总是和4阶B树的的结点数相等, 通过将黑色结点与它的红色子节点融合在一起，他们就具有等价性了

1. 每个结点最多有m个子树
2. 除了叶子结点和根结点外，每个结点度至少为「m/2」（「m/2」代表向上取整）
3. 如果一个结点有m个孩子，则他拥有m-1个元素/键
4. 根结点最多有m棵子树，至少有2棵子树（根结点不是非叶子结点时）
5. 所有叶子结点都在同一层次上

![](/public/btree.png)

### B+树特征 m阶

1. 如果一个结点有m个孩子，则他拥有m个元素
2. 每个元素不保存数据，只用来做索引
3. 所有叶子结点包含了全部关键字信息，及指向含有这些关键字记录的指针
4. 叶子结点的关键字依自小而大的顺序链接
5. 非叶子结点仅含有其子树结点中最大（或最小）关键字
6. 
![](/public/b+.png)

### 哈夫曼树和哈夫曼编码

结点的权：代表结点的重要性
结点的带权路径长度：结点深度*结点的权 (规定根结点的深度为0)
树的带权路径长度：WPL=>所有叶子结点的带权路径长度之和

WPL最小的二叉树就是哈夫曼树

如何构造哈夫曼树？
1. 将所有结点中最小的两个取出作为新树的左右子树（顺序不重要），同时这个新树根结点权值是左右子树之和
2. 将新的树和其余结点放在一起，再次重复步骤一的操作（如果有多种相同最小值，任选一种，因为哈夫曼树不唯一）
3. 继续重复步骤二，直到只剩下一棵树

![](/public/huffman.png)

哈夫曼编码 -> 构造哈夫曼树

哈夫曼编码是前缀编码，没有有歧义的前缀
字符集中的每一个字符作为叶子结点，字符出现的频度作为权值，构造哈夫曼树（左指针看作是0，右指针看作为1）

## 散列表

### 哈希冲突

某些情况，哈希值可能会出现相同的情况

**线性探测法**
找哈希表中相邻的位置上有没有为空的，只要哈希表没装满，那么我们肯定是可以找到位置装下这个元素的，这种类型的解决方案我们统称为线性探测法
开放定址法包含：线性探测法、平方探测法、双散列法等

线性探测法：发生了哈希冲突，那么我们就继续去找下一个空位
二次探测再散列法：它的查找增量序列为：1^2、-1^2、2^2、-2^2、...、q^2、-q^2，其中q <= (TableSize/2)
> 注：平均查找长度是指(ASL)每一个元素需要查找次数之和

**拉链法**
又称链地址法、链接法
把所有 "同义词" 存储在一个链表中

## 图

### 基本概念
图=顶点+边 记作G=(V,E) 其中顶点是非空集合，故图没有空图
无向图的边集使用如：{(A,B),(B,C)}，称A与B互相邻接，B与C互相邻接
有向图的边集使用如：{<A,B>,<B,C>}，称起点A邻接到终点B，起点B邻接到终点C
无向图结点的度是指与其连接的边数
有向图分为出度和入度

- 简单图：不出现自回路和重边
- 无向完全图：任意两个顶点都有一条边相连
- 有向完全图：任意两个顶点间都有由方向互为相反的两条边连接
- 连通图：对于*无向图*，任意两点都是联通的
- 强连通图：对于有向图,任意两点既有A到B的路径，也有B到A的路径
- 弱连通图：有向图如果被看作无向图时是连通的，但有些顶点之间只能单向到达而非双向
- 子图：设G=(V,E), G′=(V′,E′),若V′是V的子集,E′是E的子集，则G′是G的子图
- 极大连通子图：是原图的子图，同时也是连通的，同时具有最多顶点，即再继续增加顶点就不连通了
- 连通分量：指无向图的极大连通子图
- 强连通分量：指有向图的极大强连通子图

所以，对于原图就是连通图而言，它只有一个连通分量，就是它本身
而原图不是连通图的话，它的连通分量不止一个

记：n个顶点的无向完全图中，边数是n(n-1)/2

### 存储结构
#### 邻接矩阵
用两个数组来表示图
- 一个一维数组存储图中顶点信息
- 一个二维数组存储图中边或弧的信息，如第一行第二列值为1说明第一个元素有指向第二个元素的边

无向图的邻接矩阵是一个对称矩阵，结点的度=行+列的非零个数
有向图：每一行(列)不为0的个数，代表这个顶点的出度(入度)

#### 邻接表
当用邻接矩阵表示边数较少的图(稀疏图)的时候，数组的利用率很低
此时，我们用链式结构来解决这种问题
使用邻接表存储效率提升了，但是我们发现邻接表无法快速的得到顶点的入度
为了解决这种问题，我们可以建立一个逆邻接表，来记录指向当前顶点的顶点列表

### 图的遍历
- 深度优先搜索 DFS 树的遍历中的前序遍历是一种实现
- 广度优先搜索 BFS 树的遍历中的层序遍历是一种实现

### 生成树和最小生成树

极小连通子图: 是极大连通子图尽可能去掉可以去的边（主要讨论的是无向图，有向图不存在这种说法）
从图中找出一个极小连通子图，就是生成树
生成树的特点：
1. 包含所有顶点
2. 无环路
3. 所有顶点间都是连通的

对于带权图来说，最小生成树就是生成树的一种特殊情况
最小生成树：
1. 最小权重和
2. 包含所有顶点
3. 无环路
4. 所有顶点间都是连通的

经典的最小生成树的算法：
`普利姆（Prim）算法`
从某个顶点开始，每次选择权重最小且连接到生成树外的顶点的边，逐步扩展生成树
`克鲁斯卡尔（Kruskal）算法`
首先对所有边按权重从小到大排序，然后依次选择权重最小的边，保证不会形成环，直到构建出一个生成树

【非负权重图的单源最短路径问题】
Dijkstra算法：
1. 将起点的距离初始化为0，其他所有顶点的距离初始化为无穷大（表示尚未找到到这些顶点的路径）
2. 使用优先队列（如最小堆）来选择当前距离最小的未处理顶点，记为 𝑢
3. 对于顶点 𝑢 的每个邻居 𝑣 ，如果通过 𝑢 到达 𝑣 的路径更短，则更新 𝑣 的距离
4. 标记顶点 𝑢 为已处理，并重复上述步骤直到所有顶点都处理完毕

【非负权重图的任意两点间最短路径问题】
Floyd算法：
1. 从1开始，一直到n（n就是顶点数）的一个矩阵序列A1、A2、...An，我们需要从最初的邻接矩阵开始，从A1开始不断往后推。
2. 每一轮，我们都会去更新那些非对角线（对角线都是0，更新了还是0，所以说没必要看）、i行i列以外的元素，判断水平和垂直方向投影的两个元素之和是否比原值小，如果是，那就更新为新的值。
3. 经历n轮后，最后得到的就是最终的最短距离了。

【拓扑排序】
一种针对`有向无环图`进行排序的方法，它表示图中顶点依赖关系的正确顺序
因为前置任务只需在后续任务完成之前完成，前置任务的要求不唯一，所以拓扑排序不唯一
核心思想：通过不断移除入度为0的顶点，逐步构建拓扑序列

【关键路径】
对于`带权有向无环图`，我们想要知道最短时间路径
计算最早开始时间 ve 和最晚开始时间 vl
求关键路径的快速方法：找起点到终点的最长路径



