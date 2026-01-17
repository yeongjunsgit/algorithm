-- 코드를 작성해주세요
# SELECT E.ID, TMP.CHILD_COUNT
# FROM ECOLI_DATA AS E, (SELECT PARENT_ID, COUNT(*) AS CHILD_COUNT
#                    FROM ECOLI_DATA
#                    GROUP BY PARENT_ID) AS TMP
# WHERE E.ID = TMP.PARENT_ID
# ORDER BY ID
# 위의 코드는 실패한 이전 코드이다. 해답을 보지않고 최대한 만들어본건데 위와 같이하면 NULL인 값들이 아에 안나오는데 이는 WHERE E.ID = TMP.PARENT_ID라는 구문의 뜻이 암묵적으로 INNER JOIN을 뜻하기 때문이다.
# LEFT JOIN을 이용하면 자식이 없는 값들은 NULL 처리가 되고, 이를 그룹화 하고 COUNT(*)가 아닌 COUNT(TMP.ID)로 하면 0개로 잘 출력된다!
# 흠... JOIN에 대해서 추가적으로 공부할 필요가 있겠다!
SELECT E.ID, COUNT(TMP.ID) AS CHILD_COUNT
FROM ECOLI_DATA AS E
LEFT JOIN ECOLI_DATA AS TMP
ON E.ID = TMP.PARENT_ID
GROUP BY E.ID
ORDER BY E.ID