/******************************************************/
/* ���� : node struct ��� ���Ḯ��Ʈ                **/
/* ��¥ : 20200625                                   **/
/* �̸� : BOKDONGGIN                                 **/
/******************************************************/

#include<stdio.h>
#include<stdlib.h>  
/*******************************************************        
   <> : ǥ�� ���̺�θ��� /usr/include�� ��ġ�Ѵ�.   
   "" : ����ڰ� ������� �ҽ����� ��ġ�� �������       
        ���� �����ɴϴ�. 

   stdlib.h �� ǥ�� ���̺귯���� 
   - ���ڿ� ��ȯ, 
   - ��������
   - ���� �޸� ���� �Լ��� �����ϰ� �ִ�.
   - malloc, free �Լ��� ����Ǿ��ִ�.
 ******************************************************/

/******************************************************/
/*  node struct ����                                  */
/*  typedef : ����ü�� ��Ī                           */
/*          : ����� struct�� �ʿ����.               */
/******************************************************/


typedef struct node {
    char data;
    struct node* link;
}node;

/*  ����ü ������ ���� 1
    ����Ʈ�� �Ǿ� �ǵ� ����ü�� ����Ű�� ������       */
node* head, * end;

/*  ����ü ������ ���� 2
    ����Ʈ�� ���� ��ų ����ü���� ����Ű�� ������     */
node* node1, * node2, * node3, * node4;

/*  �Լ� ����
    - ����Ʈ�� �ʱ�ȭ ( ���� ) �ϴ� �Լ� 
    - ����Ʈ �߰��� ���θ��� ����ü�� �������ִ� �Լ� */

void Start_List(void);
void Insert_List(node*);

int main()
{

    return 0;
}

void Start_List(void)
{
    node* tmp_node;
    /* head , end ����ü �޸� �Ҵ�                  */

    /* malloc : �������� �޸𸮸� �Ҵ��ϴ� �Լ�       
       -  HEAP������ �Ҵ��Ѵ�. 
       -  �Լ� ���� : void *malloc(size_t size) 
       -  stdlib.h ������ include�ؾ���.
       -  size_t ũ�� ��ŭ �޸𸮸� �Ҵ�
       -  ���� : �Ҵ��� �޸� ù��° �ּ� ����
       -  ���� : NULL����
       -  point : �����Ҵ�� �׻� free(����) ������ !!
                                                      */
    head = (node*)malloc(sizeof(node));
    end  = (node*)malloc(sizeof(node));

    /* node1 ���� �� �޸� �Ҵ� 
       - A ���� ����
       - head�� node1�� ����Ŵ
       - node1�� end��  ����Ŵ
       - ��� head->node1->end                          */
    node1       = (node*)malloc(sizeof(node));
    node1->data = 'A';
    head->link  = node1;
    node1->link = end;
    /* node2 ���� �� �޸� �Ҵ�
       - tmp_node ���
       - B ���� ���� 
       - tmp_node = node1 �̰� tmp_node�� node2�� ����Ų��.
       - node2�� end�� ����Ų��. 
       - �׷��Ƿ� head -> node1 -> node2 -> end           */
    tmp_node       = node1;
    node2          = (node*)malloc(sizeof(node));
    node2->data    = 'B';
    tmp_node->link = node2;
    node2->link    = end;
    /*******************************************************/
    node3 = (node*)malloc(sizeof(node));
    node3->data = 'D';
    tmp_node->link = node3;
    node3->link = end;
    tmp_node = node3;
    /*******************************************************/
    node4 = (node*)malloc(sizeof(node));
    node4->data = 'E';
    tmp_node->link = node4;
    node4->link = end;
    /********************************************************/
    /* head -> node1 -> node2 -> node3 -> node4 -> end      */
}
/************************************************************/
void Insert_List(node* p_node)
{    
    node* loop_node;
    /********************************************************/
    /* head ==> end ���� ��ũ�� Ÿ���� 
       �� ���Ḯ��Ʈ�� ó������ ������                                    
       �Է��� node�� �����ͺ��� ū ���� ���� ����ü��
       ����Ű�� ����ü�� ã�´�.                            */
    /********************************************************/

    for (loop_node = head; loop_node != end; loop_node = loop_node->link)
    {
        /****************************************************/
        /* ���� �Է��� node�� �����ͺ��� ū ���� ������ ����*/
        /****************************************************/
        if (loop_node->link->data > p_node->data)
        {
            break;
        }
        /*
          - �Է��� ����ü->link : �ڱ⺸�� ū ����ü
          - �Է��� ����ü���� ū ���� ���� ����ü�� 
                   ����Ű�� ����ü->link : �Է��� ����ü
        */
        p_node->link = loop_node->link;
        loop_node->link = p_node;
        /*****************************************************/
    }

}


