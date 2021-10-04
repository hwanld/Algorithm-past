#Reculsion

ex) int func1 (int n) {
  if (n==1) return 1;
  else return n+func1(n-1);
}
라는 코드가 있다고 가정, 위 함수를 해석하는 데에는 1) 절차지향적 사고 2)귀납적 사고 2가지의 방법이 존재한다.
1) 절차지향적 사고
    func(3) -> 3+func(2) -> 3+2+func(1) -> 3+2+1+func(0) = 3+2+1+0 -> func(k)는 1~k의 합
2) 귀납적 사고
    func(1)은 1을 return한다. -> func(k)가 1~k까지의 합을 return한다고 가정한다 -> func(k+1)은 func(k)+(k+1)을 반환한다. -> func(k)는 1~k의 합
<br>
올바른 재귀 함수는 반드시 특정 입력에 대해서는 자기 자신을 호출하지 않고 종료되어아 한다. 이러한 입력을 base condition 또는 base case라고 한다. 
또한 모든 입력은 결곡 base condition으로 수렵해야 한다.
