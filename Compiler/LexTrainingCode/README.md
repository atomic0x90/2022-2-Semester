## LEX 사용법
1. Lex 프로그램 작성
	- % vi sample.l
2. Lex 처리
	- % flex sample.l => lex.yy.c가 생김
3. 컴파일
	- % gcc –o aaa lex.yy.c -lfl => aaa.exe이 생김
4. 실행
	- % ./aaa.exe => 키보드에서 입력
	- % ./aaa.exe < filename => 파일에서 입력

---

# hw1
- 여는 괄호 "("와 닫는 괄호 ")"사이에 있는 문자 "a"의 갯수 헤아리기
- 예
	- 입력: (abcda)abc(cba)
	- 출력: 3

# hw2
- 중괄호({}) 사이의 /*...*/는 주석으로 인식
- 그렇지 않은 /*...*/는 출력함
- 예
	- 입력: abc{def/*ghi*/jkl}mno/*qrs*/tuv
	- 출력: abc{defjkl}mno/*qrs*/tuv

