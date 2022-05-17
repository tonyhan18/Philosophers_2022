# Philosophers_2022
42 seoul philosophers

![image](https://user-images.githubusercontent.com/19462774/168746674-5a7600b6-ef32-4028-bc65-1f49057e0316.png)

# How to RUN
`make all`<br>
<br>
`./philo 400 200 200`<br>
<br>
`make fclean`<br>

# How to release Dead lock
1. wait and go<br>
모든 철학자가 같은 시간에 식사를 처음 시작하지 않습니다.<br>
짝수번 철학자는 일정 시간이후 첫 식사를 시작합니다.<br>
![image](https://user-images.githubusercontent.com/19462774/168747352-c6ebca43-f2b0-4550-b465-e4459ce3731b.png)

<br>

2. left-right, right-left(LIFO)<br>
많은 코드에서 세마포어를 닫는 순서를 오른쪽-왼쪽, 오른쪽-왼쪽 순서로 가는 것으로 압니다.<br>
이건 OS에서도 FIFO 방식인데... 간혹 이 방식으로 하면 DEAD LOCK이 보다 오래 지속될 가능성이 높습니다.<br>
왜냐하면 식사중인 철학자 옆에 있는 철학자는 오른쪽 포크를 기다리는데 식사중인 철학자가 왼쪽을 빨리 놓을 수록<br>
식사 중인 철학자의 옆에 있는 철학자가 오른쪽 포크를 잡을 속도 간격이 보다 좁아집니다.<br>
![image](https://user-images.githubusercontent.com/19462774/168747527-ccec6ff4-188f-4a18-ac44-71938fff7102.png)
