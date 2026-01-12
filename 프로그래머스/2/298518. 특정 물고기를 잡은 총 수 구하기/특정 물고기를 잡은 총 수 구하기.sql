-- 코드를 작성해주세요
# 이 문제를 풀면서 처음에는 GROUP BY를 이용했다... 집계함수를 쓸때 반드시 GROUP BY를 해야한다고 생각했던거 같다..
# 오히려 그 반대인데..(GROUP BY를 쓸때는 무조건 집계함수를 써야한다.)
# 초기 코드에서 GROUP BY절만 빼니까 정답을 받을거 같다. 이상한 규칙을 생각해내지 말고 있는 그대로 보고 풀어보자!
SELECT COUNT(*) AS 'FISH_COUNT'
FROM FISH_INFO AS I, FISH_NAME_INFO AS N
WHERE I.FISH_TYPE = N.FISH_TYPE AND N.FISH_NAME IN ('BASS', 'SNAPPER')
