<h3>BFS</h3>

BFS(Breadth First Search) : 다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘

![image](https://user-images.githubusercontent.com/84431962/139244888-005a18ac-2201-4920-86a9-6b9fd55c7f45.png)


각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘.

우선 BFS를 다루기 전 utility 헤더에 있는 pair를 알아두면 편리하다. pair를 이용하면 두 자료형을 묶어서 가지고 다닐 수 있다. make_pair로 값을 넣어줄 수도 있고, 그냥 중괄호를 써서 쉽게 해결할 수도 있다.


```c++
#include <bits/stdc++.h>
int main() {
	std::pair<int, int> t1 = make_pair(10,13);
	std::pair<int, int> t2 = {4, 6};
	std::cout << t2.first << ' ' << t1.second << '\n';
	if (t2 < t1) std::cout << "t2 < t1"; // t2 < t1
}
```

값의 접근은 각각 first, second를 부름으로서 가능하고 또 pair에는 미리 대소 관계가 설정되어 있어서 편하다. 알아서 앞쪽 값을 먼저 비교하고 이후 뒤쪽 값을 비교한다.

![image](https://user-images.githubusercontent.com/84431962/139244947-0c4a0f9e-88c5-413b-8854-9d8b8ef30f00.png)




위 표에서 (0,0)을 최초로 방문하였다고 가정하고, 연결되어 있는 파란색 영역에 대해서 마킹을 하는 예제를 풀어보자.

알고리즘은 다음과 같을 것이다.

 1. 시작하는 칸을 큐에 넣고 방문했다는 표시를 남김

 2. 큐에서 원소를 꺼내어 그 칸에 상하좌우로 인접한 칸에 대해 3번을 진행

 3. 해당 칸을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 삽입

 4. 큐가 빌 때 까지 2번을 반복

    *모든 칸이 큐에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(N) 

코드로 구현하게 되면 아래와 같다.

```c++
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int,int> > Q;
  vis[0][0] = 1; // (0, 0)을 방문했다고 명시
  Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입.
  while(!Q.empty()){
    pair<int,int> cur = Q.front(); Q.pop();
    cout << '(' << cur.X << ", " << cur.Y << ") -> ";
    for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
      if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
      vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
      Q.push({nx,ny});
    }
  }
}
```

큐에서 원소를 빼고 상하좌우의 칸을 확인하는 식으로 구현하면 되는데 굉장히 비효율적으로 짜지게 된다. BFS의 경우 위의 코드를 외우다 싶이 하는것도 추천되는 방법이다.  BFS를 구현함에 있어서 일반적으로 많이 하는 실수 3개는 다음과 같다.

1. 시작점에 방문했다는 표시를 남기지 않는다.
2. 큐에 넣을 때 방문했다는 표시를 하는 대신 큐에서 빼낼 때 방문했다는 표시를 남겼다.
3. 이웃한 원소가 범위를 벗어났는지에 대한 체크를 잘못했다.

