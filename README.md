# TIL
Today I Learned..

+ 2021-12-15
공부 서적 - 로버트 나일스트롬 '게임 프로그래밍 패턴'

- 코드를 얼마나 쉽게 변경할 수 있느냐가 코드 설계를 평가하는 척도가 된다.
- 코드 수정 : 업무 할당 -> 코드 팍악 -> 문제해결 코드 작성 -> ***코드정리 -> 반복..   
- 코드간 디커플링이 중요한 이유 : 작업에 들어가기 전에 알아야 할 지식의 양이 줄어듬, 즉 어느 한 코드를 고칠때 영향이 가는 다른 코드들의 정보를 알아야할 필요없음.
- 버릴 코드라면 확실히 다시 만들어야 한다는걸 주지 시켜야한다. 버릴 코드를 유지해야할 가능성이 있다면 방어적으로 잘 만들어야 할 필요가 있을지도...

- 구조가 깔끔, 성능 최적화, 기능을 빠르게 구현..  이것 모두는 불가능하므로. 균형이 중요

-저자의 조언
1. 추상화와 디커플링 잘 활용 -> 코드를 점차 쉽고 빠르게 만들 수 있다. 단 고민중엔 코드에 유연함이 필요하다는 확신이 없으면 디커플링 적용하느라 시간낭비X
2. 가정을 코드에 박아 넣어야 하는 저수준의 핵심 최적화는 가능하면 늦게.
3. 버릴코드 잘만들겟다고 시간낭비X
4. **재미있는 걸 만들고 싶다면 먼저 만드는 데에서 재미를 찾자.