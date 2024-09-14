#define maxn 5
#define maxv 1000001
#define inf 0
#define init 1
#define vType int

vType opt(vType a, vType b) {
    if (a == inf) return b;
    if (b == inf) return a;
    return (a + b) % 1000000007;
}

void KnapsackComplete(int n, int V, int w[maxn], vType v[maxn], vType dp[maxv]) {
    dp[0] = init;
    for (int i = 1; i <= V; ++i) {
        dp[i] = inf;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = w[i]; j <= V; ++j) {
            dp[j] = opt(dp[j], dp[j - w[i]] + v[i]);
        }
    }
}

int n, V;
int w[maxn] = { -1, 25, 10, 5, 1 };
vType v[maxn] = { -1, 0, 0, 0, 0 };
vType dp[maxv];

class Solution {
public:
    int waysToChange(int n) {
        KnapsackComplete(4, n, w, v, dp);
        return dp[n];
    }
};

// dp[i][j] ����ǰ i ��Ӳ����ϳ� j �ֵķ�����
/*
��ô�� i ��Ӳ�ҿ��Բ�ѡ������������ dp[i-1][j]
�� i ��Ӳ��Ҳ����ѡ 1����2���� k��
��ᷢ���������ȫ�����ǳ�����
�������յ�״̬ת�Ʒ��̣�����д�ɣ�
dp[i][j] = dp[i-1][j] + dp[i][j - w[i]]

������ȫ�������������ڣ�
1��max ����� �Ӻ�
2�������Ŀû�м�ֵһ˵��Ҳ����ÿ����Ʒ��ֵΪ 0
���˾�Ҫ���ˣ������ 25�֣�10�� ��ʲô������
���������������˵�۸�

*/