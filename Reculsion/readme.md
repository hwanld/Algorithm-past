#Reculsion
<pre>
ex) int func1 (int n) {<br>
    if (n==1) return 1;<br>
    else return n+func1(n-1);<br>
}</pre>
위 함수를 해석하는 데에는 1) 절차지향적 사고 2)귀납적 사고 2가지의 방법이 존재한다.
1) 절차지향적 사고
    func(3) -> 3+func(2) -> 3+2+func(1) -> 3+2+1+func(0) = 3+2+1+0 -> func(k)는 1~k의 합
2) 귀납적 사고
    func(1)은 1을 return한다. -> func(k)가 1부터 k까지의 합을 return한다고 가정한다 -> func(k+1)은 func(k)+(k+1)을 반환한다. -> func(k)는 1부터 k까지의 합
    
&nbsp;&nbsp;&nbsp;올바른 재귀 함수는 반드시 특정 입력에 대해서는 자기 자신을 호출하지 않고 종료되어아 한다. 이러한 입력을 base condition 또는 base case라고 한다. 
또한 모든 입력은 결국 base condition으로 수렴해야 한다. 위 코드의 경우, n=1인 경우에 자기 자신을 호출하지 않고 종료가 되니 이것이 base condition이고 우리는 이 함수에 자연수만 넣을테니 결국 모든 입력은 n=1으로 수렵하게 된다. 위 두개의 조건을 반드시 만족하여야 한다.
<br><br>
&nbsp;&nbsp;&nbsp;재귀 함수에서는 함수를 명확하게 정의해야 한다. 함수의 인자로 어떤 것을 받을 것인지, 그리고 어디까지 계산한 후 자기 자신에게 넘겨줄지를 의미한다. 또한 모든 재귀 함수는 재귀 구조 없이 반복문만으로 동일한 동작을 하는 함수를 만들 수 있다. 
<br><br>
&nbsp;&nbsp;&nbsp;재귀 함수는 자기 자신을 여러 번 호출하게 되는데, 이렇게 되면 생각보다 되게 비효율적일 수 있다. 예를 들어 fibo(5)의 값을 계산하기 위해서 이미 사용하였던 fibo(3)의 값을 2번 호출하는 등의 단점이 존재한다. 따라서 반복문으로 구현이 가능할 때는 반복문을 사용하여서 구현하는 것이 오히려 시간 복잡도 면에서 우위를 점하는 경우가 있다. 또한 fibo와 같이 이전에 사용한 값을 다시 사용해야 할때는 굳이 재귀를 사용하지 않고 일전에 공부하였던 DP를 사용한다면 훨씬 유리하다.
<br><br>
<pre>
ex) int func1 (int a, int b, int m) {<br>
      int val = 1;
      while(b--) val *= a;
      return val % m;
}</pre>
a^b를 m으로 나눈 나머지를 구할 때 가장 쉬운 방법은 a를 b번 곱하고 m으로 나눈 나머지를 return하는 것이다. 하지만 위의 코드는 int overflow때문에 1이 아닌 0이 return 되는 경우가 생긴다. 예를 들어, func1(6,100,5)를 호출하게 되면 1이 아닌 0을 return하게 된다. 이러한 것을 막기 위해서 long long을 사용하여 방지할 수도 있으나 그 역시 자료형의 허용 범위가 정해져 있기 때문에 long long overflow 가 발생할 수 있다. 하지만  <a href="https://github.com/wkazxf/Basic-Algorithm-Study/commit/d43bfd97425be7b2fa4ad9b864c1fb95e036b44c" target="_blank">BOJ1629</a> 코드처럼 한다면 상관없이 구할 수 있다.
<br><br>
또 다른 문제로는 하노이탑이 있다. BOJ11729
