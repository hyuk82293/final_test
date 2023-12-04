#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *source, *destination;
    char ch;

    // 명령줄 인수가 부족한 경우 에러 메시지 출력
    if (argc != 3) {
        fprintf(stderr, "사용법: %s 소스_파일 대상_파일\n", argv[0]);
        return 1;
    }

    // 소스 파일 열기
    source = fopen(argv[1], "rb");
    if (source == NULL) {
        perror("소스 파일 열기 오류");
        return 1;
    }

    // 대상 파일 열기
    destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        perror("대상 파일 열기 오류");
        fclose(source);
        return 1;
    }

    // 파일 내용 복사
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    // 파일 닫기
    fclose(source);
    fclose(destination);

    printf("파일이 성공적으로 복사되었습니다.\n");

    return 0;
}
