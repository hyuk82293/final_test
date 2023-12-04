#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *source, *destination;
    char ch;

    // ����� �μ��� ������ ��� ���� �޽��� ���
    if (argc != 3) {
        fprintf(stderr, "����: %s �ҽ�_���� ���_����\n", argv[0]);
        return 1;
    }

    // �ҽ� ���� ����
    source = fopen(argv[1], "rb");
    if (source == NULL) {
        perror("�ҽ� ���� ���� ����");
        return 1;
    }

    // ��� ���� ����
    destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        perror("��� ���� ���� ����");
        fclose(source);
        return 1;
    }

    // ���� ���� ����
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    // ���� �ݱ�
    fclose(source);
    fclose(destination);

    printf("������ ���������� ����Ǿ����ϴ�.\n");

    return 0;
}
