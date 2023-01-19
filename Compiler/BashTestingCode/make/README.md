## make 시스템의 필요성

- 다중 모듈 프로그램을 구성하는 일부 파일이 변경된 경우?
	- 변경된 파일만 컴파일하고, 파일들의 의존 관계에 따라서 필요한 파일만 다시 컴파일하여 실행 파일을 만들면 좋다.

- 예
	- copy.c 소스 코드를 수정
	- 목적 파일 copy.o 생성
	- 실행파일을 생성

- make 시스템
	- 대규모 프로그램의 경우에는 헤더, 소스 파일, 목적 파일, 실행 파일의 모든 관계를 기억하고 체계적으로 관리하는 것이 필요
	- make 시스템을 이용하여 효과적으로 작업

- makefile
	- 실행 파일을 만들기 위해 필요한 파일들과 그들 사이의 의존 관계, 만드는 방법 등을 기술
	- make 시스템은 메이크파일을 이용하여 파일의 상호 의존 관계를 파악하여 실행 파일을 쉽게 다시 만듬
- $ make [-f 메이크파일]
	- 옵션이 없으면 Makefile 혹은 makefile을 사용