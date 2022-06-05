C++ 이 main language 이며, 추가 언어로 PYTHON 사용중입니다.

1. BOJ 알고리즘 문제 풀이
2. 자료구조 구현
3. 알고리즘 시간복잡도 분석



## 1. 우선순위 큐

#### PQ-Sort 알고리즘

~~~
Algorithm PO-Sort(S, C)
Input Sequence S, Comparator C for the elements of S
Output Sequence S sorted in increasing order according to C
P <- priorty queue with comparator C

while ㄱs.empty()
  e <- S.front()
  S.eraseFront()
  P.insert(e, ∅)
  
while ㄱP.empty()
  e <- P.removeMin()
  S.insertBack(e)
~~~

#### 시간 복잡도

1. unsorted list 로 PQ 를 구현
> 삽입(insert) : O(1)
탐색(min) : O(n)
삭제(removeMin) : O(n)

2. sorted list 로 PQ 를 구현
> 삽입(insert) : O(n)
탐색(min) : O(1)
삭제(removeMin) : O(1)

3. Selection Sort (선택정렬)

 > O(n^2)
   - PQ 배열에 카피후, 최솟값을 PQ 에서 일일이 찾아내서 시퀀스에 옮김

4. Insertion Sort(삽입정렬)

 >worst case : O(n^2)  // best case : O(n)
   - PQ 배열에 원소 하나하나를 넣을때마다 정렬상태를 유지. 
정렬 완료후에 시퀀스에 PQ 내용을 카피


#### in-place sort 선택 정렬

> O(n^2) = n(n+1)/2
- 시퀀스의 범위를 1칸씩 늘려가면서 유입되는 원소를 정렬시켜줌
- 즉, PQ 에서 최솟값을 찾아서 시퀀스에 삽입 (시퀀스의 범위를 1칸씩 늘려감)

#### in-place 삽입정렬
> O(n^2) = n(n+1)/2  // best : O(n), average : n^2/4
- PQ의 범위를 1칸씩 늘려가면서 유입되는 새로운 원소를 정렬시켜줌

---

## 2. 힙(Heap)

- 순서 조건 : parent 로 올라갈수록 값이 작아짐
- 구조적 조전 : 완전이진트리 


### 힙을 PQ 로 구현시
- insert : O(log n)    => 맨끝에 추가 O(1) + UpHeap O(log n)  
- remove : O(log n)  => 최솟값 찾기(루트) O(1) + 다운힙(비교연산2번) O(log n)
- min(), max() : 최솟값(or 최댓값) 은 루트 노드에 위치

### Heap-sort 구현 2가지 : 두 구현모두 O(nlog n)

1. 일반구현 => O(nlog n) + O(log n)

 - 1단계 : insert연산 n번 진행 = n x O(log n)
 - 2단계 : remove연산 n번 진행 = n x O(log n)
 
 
 2. Bottom-up Heap construction => O(n) + O(nlog n)

- 1단계 : insert연산을 Heap Merge 방식으로 n번 진행 = O(n)
   - 배열기반 힙에 insert를 하는데, 한 스탭에 한 레벨씩 채워나감
   - 한 레벨을 채우면, 병합된 각 힙에 대해서 다운힙을 수행

- 2단계 : O(nlog n)
   - remove 연산 n번 진행 = n x O(log n)
    
### Bottom-up Heap Construction 분석

- 왜 Merge 를 사용했을때 힙을 생성하는 1단계 과정이 O(n) 인가?

> 최악의 경우 비교연산 횟수 = 2 x (빨간 간선 수) ≤ 2 x (총 간선수) ≤ 2 x (총 노드의 수 n)
=> 비교연산 횟수 ≤ 2n = O(n) 

---

## 3. BST

- 왼쪽자식 key < 부모 key < 오른쪽 자식 key

- 사용공간 : O(n)
- 탐색(TreeSearch), 삽입(put), 삭제(erase) 연산 모두 O(h)
  - worst case : O(n) => 트리가 한쪽으로 쭉 나열된 경우
  - best case : O(log n) => 균형이진탐색트리 (트리가 완전이진트리인 경우)

### TreeSearch : O(h)
~~~
Algorithm TreeSearch(k, v)
  if(v.isExternal())
    return v
  if k < v.key()
    return TreeSearch(k, v.left())
  else if k == v.key()
    return v
  else if k > v.key()
    return TreeSearch(k, v.right())
~~~

### put : O(h)

- TreeSearch() 로 삽입될 external 노드에 도달해서 그 external 노드를 key 값 k를 가지는 새로운 노드로 대체한다. 그리고 양쪽에 external 자식을 매단다.

### erase : O(h)

#### Case1) 왼쪽 or 오른쪽 자식이 external인 경우
   - 삭제하려는 노드 찾기 : O(h)
  - external 자식과 같이 한묶음으로 삭제시킨다 : O(1)
  - 삭제된 노드의 부모와 삭제안된 나머지 한 자식을 이어준다 : O(1)

#### Case2) 왼쪽, 오른쪽 자식이 모두 external 인 경우
  - 삭제하려는 노드 찾기 : O(h)
  - 두 자식 중 아무거나 한 묶음으로 같이 삭제 : O(1)
  - 삭제된 노드의 부모와, 삭제안된 나머지 한 자식을 이어준다 : O(1)

#### Case3) 두 자식 모두 internal 인 경우

- 삭제하려는 노드 k 찾기 (=탐색) : O(h)
- successor 찾기 (노드 k의 오른쪽 서브트리에 대해 중위순회를 진행) : O(h)
- 찾아낸 successor의 값을 노드 k에 덮어씌우기 : O(1)
- 기존의 successor 를 가진의 왼쪽 external 과 함께 삭제 : O(1)


---


## 4. AVL 트리

- 탐색, 삽입, 삭제 연산모두 O(log n) (=O(h))

#### find 연산 : O(log n)

- 일반적인 BST 처럼 TreeSearch() 호출


#### insert 연산 : O(log n)

>1.일반 BST 연산처럼 TreeSearch() 호출해서 삽입될 external 노드 위치 찾아냄 : O(log n)
2.  삽입 후 AVL의 특성(높이 차가 최대 1) 을 위반하는지 체크: O(log n)
3. 재구성(restructuring) 진행  : O(1)
  - 3-1. z, y, x를 설정하고 3개의 트리 재구성 : O(1)
=> single rotation, double rotataion 모두 O(1)
   - 3-2. 서브트리 T1 or T1 + T2 를 옮기기 : O(1)


- single rotation : z,y,x 가 한 방향으로 연결된 상황에서 발생
- double rotation : z,y,x 가 꺾인 상황에서 발생

#### removal 연산 : O(log n)

>1. 삭제할 노드 탐색 : O(log n)
2. 찾아낸 노드 삭제 : O(1) / O(log n)
(successor 를 찾고 삭제하는 과정이 포함된 case만 O(log n)
3. 삭제 후 AVL의 특성(높이 차가 최대 1) 을 위반하는지 체크 : O(log n)
4. 문제가 발생한 경우, 재구성(restructuring) 진행 : O(log n)

(4번의 경우 재구성 과정 자체는 O(1) 이지만, 재구성 알고리즘을 최악의 경우 O(log n) 번 호출할 수 있다.)

- z : 문제가 발생한 노드
y : 삭제가 일어난 반대 경로에 있는 z의 자식 노드
x : 두 서브트리중 높이가 더 높은 서브트리의 루트노드 / 높이가 같은경우 single rotation 발생할 수 있는 곳으로 설정 

---

## 5. 딕셔너리

### 구현방법

1.로그파일 : unsorted 링크드리스트 기반
- put : O(1)
- find, erase : O(n)

2.Search Table (Look up table) : sorted array 기반, 이진탐색 활용 
- find : O(log n)
- put : O(n)
- erase : O(n)

=>  삽입, 삭제가 왜 O(n) 인가?
- find 연산으로 삽입/삭제될 적절한 위치 찾는데 O(log n) + 최악의 경우 가운데에서 삽입/삭제되면 n/2 개의 데이터를 뒤 or 앞으로 이동시켜야하므로 O(n)

3. BST 
 - 탐색,삽잆,삭제 모두 최악의 경우 O(n)
 
4. AVL 트리
- 탐색, 삽입, 삭제 모두 최악의 경우 O(log n)

5. Hash Table
- 모든 해싱 기법들이 탐색, 삽입, 삭제 연산이 expected time 으로 O(1)
- 최악의 경우는 O(n)


---

## 6. Hash Table

- 해시함수 h(k) = h2(h1(k))
   - h1(k) : hash code, h2(k) : Compression function
   - h2(k) 구현방법 : Division ( = y mod N) // MAD ( = (ay+b) mod N)  
     - 배열의 크기 N 은 소수로 설정하자!
     
### 해시 테이블 구현방법
- load factor α (=n/N)  =  평균연산 횟수


>  - 해시테이블 시간복잡도
>>모든 해싱 기법은 탐색, 삽입, 삭제 연산 실행시간이 동일하다.
expected time : O(1)
worst case : O(n)
- 사용공간 : O(n)

### 1. Seperate Chaining

- 탐색 : 최악의 경우  => 특정 인덱스에 대해서만 collision이 발생해서 그 인덱스에만 모든 key값들이 싹다 저장

### 2. Open Addressing (개방 주소법)

- 종류 : 선형탐사 (liner probing), 이중해싱 (Double Hashing)
- 추가적인 메모리 공간 사용 x

#### 2-1. Linear Probing

- find 연산

case1) 빈 인덱스를 만난경우 => 후보 명단에 없는것
case2) 원하는 key 값을 만난경우 
case3) 충돌이 발생하는 경우 => 다음 셀을 확인하러간다. 탐사를 또 진행

~~~
Algorithm find(k)
  i < - h(k)              // 인덱스
  p <- 0                  // probing 총 횟수
  repeat
    c <- A[i]    
    if c = Ø                // 1. 원하는 key값을 못 찾은채로 빈 인덱스를 만난경우
      return null           //    => 후보 명단에 없는거임
    else if c.key() = k     //  2. 원하는 key값 찾은경우
      return c.value()
    else                    //  3. 충돌이 발생하는 경우
      i <- (i+1) mod N      // => 다음 셀을 확인하러 나간다. 탐사를 또 진행
      p <- p + 1
  until p = N
  return null  // 배열의 모든 인덱스에 대해 싹다 뒤져봤지만 못찾은 경우
~~~

- erase 연산
   - AVAILABLE 은 삽입 연산시에는 비어있다고 인식되서 그냥 데이터를 삽입하면 된다.
 
   - 반면 탐색, 삭제 연산시에는 빈 상태가 무시되고( = 빈 상태가 아니라고 인식되고) 다음 인덱스로 넘어감


#### 2-2. 이중해싱

- 1차 해시함수 : h(k) = k mod N
- 2차 해시함수 : d(k) = q - k mod q  (q: N보다 작은 소수중 가장 큰 소수)

- "2차 해시함수의 결과값 d(k)" 만큼 이동해서 탐색을 계속 진행
- j번쨰로 탐색하게 되는 인덱스 : (i +j x d(k) ) mod N = h( h(k) + j x d(k) )
     - 즉, 인덱스 i (= 1차해시함수의 결과값 i을 탐색의 시작 인덱스로 설정 ) 가 비었다면 2차 해시함수의 결과값(=d(k)) 만큼 계속 이동하면서 탐색을 진행하는 것이다.

     - 1차해시함수를 바깥에 또 적용시킨 이유는, 환형배열로 구현하기 위함
     
     
---

## 그래프

#### ADT
1. u.isAdjacentTo(v) : 두 정점이 인접해 있는지를 리턴
2. v.incidentEdges() : 정점 v와 연결된 edge 들을 모두 리턴
3. e.endVertices() : edge e의 양끝 정점을 리스트 형식으로 리턴
4. e.opposite(v) : edge e의 양끝 정점중에 정점 v말고 또 다른 정점을 리턴
5. vertices() : 모든 정점으로 구성된 리스트를 리턴
6. edges() : 모든 edge 들로 구성된 리스트를 리턴
7. insertVertex(o) : o 라는 데이터를 갖는 정점을 insert
8. insertEdge(v, w, o) : 정점 v,w 를 연결하면서 데이터 o를 갖는 edge를 추가
9. eraseVertex(v) : 정점 v를 v와 연결된 edge들과 함께 삭제
10. eraseEdge(e) : edge 를 삭제


![](https://velog.velcdn.com/images/msung99/post/5e97cc42-bb9d-470f-9178-4520bcc7d0b5/image.png)

### Edge List (간선 리스트)
- vertex 오브젝트 구성요소
1) 데이터 
2) vertex 시퀀스에 다시 돌아가기 위한 주소값

- edge 오브젝트 
1) 데이터 
2) source vertex 오브젝트 주소값 
3) destination vertex 오브젝트 주소값
4) edge 시퀀스에 다시 돌아가기 위한 주소값

- edge 에서 vertex 는 따라갈수 있는데, vertex 에서 edge 따라갈 수 없다!

- v.incident() : O(m)
    - edge 시퀀스에 있는 모든 edge 오브젝트들이 가리키는 vertex 오브젝트가 누군지 일일이 확인해야함
    
 - v.isAdjacentTo(v) : O(m)
    - 양끝점이 u, v 인 edge 오브젝트가 나올때까지 edge 시퀀스에서 찾아야함

     ---
    
### Adjacency list (인접 리스트)

![](https://velog.velcdn.com/images/msung99/post/4f79d9e4-7ff2-44ba-8b98-925cfb92ac67/image.png)

- incidence 시퀀스
  - 각 정점에 대한 시퀀스는 해당 정점의 차수만큼 크기를 가짐
   - 시퀀스의 각 노드들은 해당 정점과 연결된 edge 오브젝트를 가리킴

- vertex 오브젝트의 구성요소
  1) 데이터
  2) vertex 시퀀스에 다시 돌아가기 위한 주소값
  3) incidence 시퀀스의 시작 주소

- edge 오브젝트 구성요소
1) 데이터 
2) source vertex 오브젝트 주소값
3) destination vertex 오브젝트 주소값 
4) source vertex 오브젝트의 incidence 시퀀스에서 해당 원소에 대한 주소값
5) destination vertex 오브젝트의 incidence 시퀀스에서 해당 원소에 대한 주소값
6) edge 시퀀스로 다시 돌아가기 위한 주소값

#### 1. 사용공간 : O(n+m)

#### 2. v.incident() : O(1)
- 정점 v의 incidence 시퀀스 각 원소들이 가리키는 edge 오브젝드들을 모두 조회

#### 3.insertVertex(x) : O(1)
- vertex 시퀀스에 새로운 원소 만들고, 새로운 vertex 오브젝트도 만들고 vertex 시퀀스에 추가해주면 끝

#### 4.insertEdge(v, w, o) : O(1)
 - 1) edge 오브젝트 만들고, edge 시퀀스에 매달기
 - 2) 양끝 정점의 incidence 시퀀스에 새로운 원소 만들고 edge 오브젝트랑 서로 가리키게 하기
 - 3) edge 오브젝트가 양끝 vertex 오브젝트를 가리키게 하기 
 
#### 5.eraseEdge(e) : O(1)
=> 엣지를 삭제하면 양끝 정점의 차수가 1씩 감소한다.

  -  1) edge 오브젝트를 삭제
  - 2) edge 시퀀스에서 해당하는 원소 삭제
  - 3) edge 오브젝트가 가리키던 양끝 정점의 (자신과 연결된 정점들의) incidence 시퀀스의 해당 원소들도 삭제

#### 6.eraseVertex(v) : O(deg(v))

- 자신과 연결된 모든 edge 들을 삭제하므로 차수만큼 eraseEdge() 연산을 수행
- 1) 삭제하려는 vertex 의 incidence 시퀀스의 원소들이 가리키고 있는 모든 edge 들에 대해 eraseEdge() 를 수행
- 2) 자신과 연결된 모든 edge 가 삭제된 후, vertex 를 제거


#### 7.u.isAdjacentTo(v) : O(min(deg(v), deg(v))

case1) 정점 u,v 의 차수를 알고있는 경우
  - 1) 더 낮은 차수를 가진 정점을 찾기
  - 2) 정점 w의 차수가 더 낮은 경우, w의 incidence 시퀀스가 가리키는 모든 edge 오브젝들을 조회하면서
  - 3) edge 오브젝트 중에 반대편(opposite) 정점 v를![]
 가리키는게 있는지 확인
  
case2) 정점 u, v 의 차수(degree) 를 모르는 경우

   - 정점 u,v 를 계속 번갈아가면서 반대편(opposite) 정점을 가리키는 edge 오브젝트가 있는지 확인
   
   
   ---

### Adjacency Matrix (인접행렬)

- 인덱스 데이터 n 과 m 을 저장하고 있는 두개의 vertex 오브젝트를 가리키는 edge 오브젝트의 주소값을 2차원 배열 (n, m) 좌표와 (m, n) 좌표에 저장한다.

![](https://velog.velcdn.com/images/msung99/post/f8c506b5-250c-4e9d-a524-e228bbcf9571/image.png)


#### 1. u.isAdjacent(v) : O(1)

- u 와 v 의 인덱스 데이터 값 i, j 로 행렬 (i, h) 에 담긴 주소가 NULL 인지 아닌지를 판단

#### 2. insertVertex(o), eraseVertex(v) : O(n^2)

- 1) vertex 시퀀스에 삽입, 삭제하는 과정: O(1)
- 2) 행렬의 크기를 늘리거나 줄이고, 기존 행렬의 원소들을 카피 : O(n^2)
- 3) 새로운 행렬에 주소값 삽입


#### 3. insertEdge(v, w, o) : O(1)

- 1) 새로운 edge 오브젝트와 edge 시퀀스에 새로운 원소를 생성
- 2) edge 오브젝트가 양끝 정점 v, w 를 가리키게 하기
- 3) edge 시퀀스와 edge 오브젝트 연결시켜주기
- 4) 행렬 ( i, j ) 에다 새로만든 edge 오브젝트의 주소값을 써주기
   - 이때 i, j 를 정하는 방법은 edge 오브젝트가 가리키는 양끝 정점에 저장된 인덱스 데이터를 얻어내면 된다.

#### 4. eraseEdge(e) : O(1)

- 1) edge 오브젝트가 가리키는 양끝 정점에 저장된 인덱스 데이터를 확인
- 2) 행렬 (i, j) 에 저장된 주소값을 NULL 로 변경
- 3) edge 오브젝트와 edge 시퀀스에서 해당 원소 삭제
 

#### 5. v.incidentEdges() : O(n)

- 1) v의 인덱스 데이터 얻어오기
- 2) v의 인덱스에 해당하는 행렬의 행 or 열로 이동하며 모든 원소를 조사한다. 
  - ex) 인덱스 데이터 = 2 이고 행렬이 3x3 인 경우, (2,0), (2,1), (2,2) 를 조사하거나 또는 (0,2), (1,2), (2,2) 를 조사
  
=> 따라서 행 or 열의 크기인 O(n) 만큼의 시간이 걸린다.

---

### DFS

- 수행시간 : O(n+m)
   - 1. 모든 정점, 간선 label 초기화 => O(n+m)
   - 2. Σv ( O(1) + O(deg(v)) ) = O(n) + O(2m)

#### 용어정리
- Spanning subgraph : 기존 그래프 G의 모든 정점을 포함하는 subgraph
- Connected component : connected subgraph 중에 가장 큰 그래프

#### 수도코드

- edge의 label 종류 : UNEXPLORED, DISCOVERY, BACK
- vertex의 label 종류 : UNEXPLORED, VISITED

~~~
Algorithm DFS(G)
  Input graph G
  Output labeling of the edges of G as discovery edges and back edges
  for all u ∈ G.vertices()
    u.setLabel(UNEXPLORED)
  for all
  for all e ∈ G.vertices()
    e.setLabel(UNEXPLORED)
  for all v ∈ G.vertices()
    if v.getLabe() = UNEXPLORED
      DFS(G, v)
~~~

~~~
Algorithm DFS(G, v)
  Input graph G and start vertex of G
  Ouput labeling of the edges of G in the connected component of v as discovery edges and back edges
  v.setLabel(VISITED)
  for all e ∈ G.incidentEdges(v)
    if e.getLabel() = UNEXPLORED
      w <- e.opposite(v)
      if w.getLabel() = UNEXPOLRED
        e.setLabel(DISCOVERY)
        DFS(G, w)
     else
       e.setLabel(BACK)
~~~

---

### BFS
- Σv O(1)+O(deg(v)) = O(n) + O(2m) = O(n+m) 
- Li : 시작정점으로 부터 거리가 i인 정점들의 집합 (시퀀스)
- CROSS 라는 label 상태가 추가

~~~
Algorithm BFS(G, v)
  L0 <- new empty sequence // queue
  L0.insertBack(v)
  i <- 0
  while ㄱ Li.empty()
    Li+1 <- new empty sequence
    for all v ∈ Li.elements()
      for all e ∈ v.incidentEdges()
        if e.getLabel() = UNEXPLORED
          w <- e.opposite(v)
          if w.getLabel() = UNEXPLORED
            e.setLabel(DISCOVERY)
            w.setLabel(VISITED)
            Li+1.insertBack(w)
          else
            e.setLabel(CROSS)
   i <- i+1
~~~


---


### 위상정렬(Topological Sorting)

- 위상정렬을 인접 리스트로 구현하면 O(n+m) 시간이 걸린다.
- 위상순서 : 나에게서 다음 정점으로 가는 간선이 있는경우, 그 다음 정점은 순서가 나보다 나중에 나와야하는 순서를 가진다.

#### 위상정렬

- outgoing 간선이 없는 정점을 넘버링 진행


#### 구현1. DFS 로 구현

~~~
Algorihtm topologicalDFS(G)
  Input dag G
  Output topological ordering of G
  n <- G.numVertices()
  for all u ∈ G.vertices()
    u.setLabel(UNEXPLORED)
  for all v ∈ G.vertices()
    if v.getLabel() = UNEXPLORED
      topologicalDFS(G, v)
~~~

~~~
Algorithm topological(G, v)
  Input graph G and start vertex of V
  Output labeling of the vertices of G in the connected component of v
  v.setLabel(VISITED)
  for all e ∈ v.outEdges()
    w <- e.opposite(v)
    if w.getLabel() = UNEXPLORED
      { e is a discovery edge }
      topologicalDFS(G, w)
    else
      { e is a forward or cross edge }
  Label v with topological number of n
  n <- n-1
~~~


#### 구현2. 스택으로 구현

- incoming 간선이 없는 정점을 스택에 push 

~~~
Algorthm Topological(G)
  H <- G
  n <- G.numVertices()
  while H is not empty do
    Let v be vertex width no outgoing edges
    Label v <- n
    n <- n-1
    Remove v from H
~~~

~~~
Algorithm Topological(G)
S <- an initally empty stack
for all u in G.vertices() do     //  incoming 간선이 없는 정점들을 모두 스택에 push
  Let incounter(u) be the in-degree of u    
  if incounter(u) = 0 then S.push(u)       
i <- 0 
  while !S.empty() do
    u <- S.pop()
    Let u be vertex number i in the topological ordering
    i <- i + 1
    for all outgoing edges (u, w) of u do
      incounter(w) <- incounter(w) - 1
      if incounter(w) = 0 then S.push(w)
~~~

![](https://velog.velcdn.com/images/msung99/post/1d78989e-9b69-4fe4-8055-e8a97505774b/image.png)

