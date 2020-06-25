/******************************************************/
/* 설명 : node struct 사용 연결리스트                **/
/* 날짜 : 20200625                                   **/
/* 이름 : BOKDONGGIN                                 **/
/******************************************************/

#include<stdio.h>
#include<stdlib.h>  
/*******************************************************        
   <> : 표준 라이브로리로 /usr/include에 위치한다.   
   "" : 사용자가 사용중인 소스파일 위치의 헤더파일       
        에서 가져옵니다. 

   stdlib.h 는 표준 라이브러리로 
   - 문자열 변환, 
   - 난수생성
   - 동적 메모리 관련 함수를 포함하고 있다.
   - malloc, free 함수가 선언되어있다.
 ******************************************************/

/******************************************************/
/*  node struct 선언                                  */
/*  typedef : 구조체의 별칭                           */
/*          : 선언시 struct가 필요없다.               */
/******************************************************/


typedef struct node {
    char data;
    struct node* link;
}node;

/*  구조체 포인터 선언 1
    리스트의 맨앞 맨뒤 구조체를 가리키는 포인터       */
node* head, * end;

/*  구조체 포인터 선언 2
    리스트로 연결 시킬 구조체들을 가리키는 포인터     */
node* node1, * node2, * node3, * node4;

/*  함수 선언
    - 리스트를 초기화 ( 생성 ) 하는 함수 
    - 리스트 중간에 새로만든 구조체를 삽입해주는 함수 */

void Start_List(void);
void Insert_List(node*);

int main()
{

    return 0;
}

void Start_List(void)
{
    node* tmp_node;
    /* head , end 구조체 메모리 할당                  */

    /* malloc : 동적으로 메모리를 할당하는 함수       
       -  HEAP영역에 할당한다. 
       -  함수 원형 : void *malloc(size_t size) 
       -  stdlib.h 파일을 include해야함.
       -  size_t 크기 만큼 메모리를 할당
       -  성공 : 할당한 메모리 첫번째 주소 리턴
       -  실패 : NULL리턴
       -  point : 동적할당시 항상 free(해제) 해주자 !!
                                                      */
    head = (node*)malloc(sizeof(node));
    end  = (node*)malloc(sizeof(node));

    /* node1 연결 및 메모리 할당 
       - A 값을 저장
       - head가 node1을 가리킴
       - node1은 end를  가리킴
       - 결론 head->node1->end                          */
    node1       = (node*)malloc(sizeof(node));
    node1->data = 'A';
    head->link  = node1;
    node1->link = end;
    /* node2 연결 및 메모리 할당
       - tmp_node 사용
       - B 값을 저장 
       - tmp_node = node1 이고 tmp_node는 node2를 가리킨다.
       - node2는 end를 가리킨다. 
       - 그러므로 head -> node1 -> node2 -> end           */
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
    /* head ==> end 까지 링크를 타고가며 
       즉 연결리스트의 처음부터 끝까지                                    
       입력한 node의 데이터보다 큰 값을 가진 구조체를
       가리키는 구조체를 찾는다.                            */
    /********************************************************/

    for (loop_node = head; loop_node != end; loop_node = loop_node->link)
    {
        /****************************************************/
        /* 만약 입력한 node의 데이터보다 큰 값이 나오면 종료*/
        /****************************************************/
        if (loop_node->link->data > p_node->data)
        {
            break;
        }
        /*
          - 입력한 구조체->link : 자기보다 큰 구조체
          - 입력한 구조체보다 큰 값을 가진 구조체를 
                   가리키는 구조체->link : 입력한 구조체
        */
        p_node->link = loop_node->link;
        loop_node->link = p_node;
        /*****************************************************/
    }

}


