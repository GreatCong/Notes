#include <QCoreApplication>

#include "RB_Tree.h"
#include <stdio.h>

#define CHECK_INSERT 0    // "插入"动作的检测开关(0，关闭；1，打开)
#define CHECK_DELETE 0    // "删除"动作的检测开关(0，关闭；1，打开)
#define LENGTH(a) ( (sizeof(a)) / (sizeof(a[0])) )

void  RB_Tree_test(){
    int data[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
        int i, ilen=LENGTH(data);
        RBRoot *root=NULL;

        root = create_rbtree();
        printf("== 原始数据: ");
        for(i=0; i<ilen; i++)
            printf("%d ", data[i]);
        printf("\n");

        for(i=0; i<ilen; i++)
        {
            insert_rbtree(root, data[i]);
    #if CHECK_INSERT
            printf("== 添加节点: %d\n", data[i]);
            printf("== 树的详细信息: \n");
            print_rbtree(root);
            printf("\n");
    #endif
        }

        printf("== 前序遍历: ");
        preorder_rbtree(root);

        printf("\n== 中序遍历: ");
        inorder_rbtree(root);

        printf("\n== 后序遍历: ");
        postorder_rbtree(root);
        printf("\n");

        if (rbtree_minimum(root, &i)==0)
            printf("== 最小值: %d\n", i);
        if (rbtree_maximum(root, &i)==0)
            printf("== 最大值: %d\n", i);
        printf("== 树的详细信息: \n");
        print_rbtree(root);
        printf("\n");

    #if CHECK_DELETE
        for(i=0; i<ilen; i++)
        {
            delete_rbtree(root, data[i]);

            printf("== 删除节点: %d\n", data[i]);
            if (root)
            {
                printf("== 树的详细信息: \n");
                print_rbtree(root);
                printf("\n");
            }
        }
    #endif

    destroy_rbtree(root);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RB_Tree_test();//测试红黑树

    return a.exec();
}
