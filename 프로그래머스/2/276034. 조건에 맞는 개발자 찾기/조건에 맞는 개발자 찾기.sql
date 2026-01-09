-- 코드를 작성해주세요
## 이 문제를 풀때 발생했던 문제
# 1. 서브쿼리의 결과와 연산 한 결과를 괄호로 싸주지 않았음 그래서 에러가 남
# 2. 2개의 언어를 찾을때 OR 연산을 해서 동일한 기능을 가진 SQL문을 2번이나 썼으나 IN연산을 이용해 하나의 SQL문으로 합침
# 3. 그러나 단순히 2번을 하면 반환하는 값이 1개 이상일 확률이 있으므로 반드시 SUM()을 이용하여 1개의 값을 반환해야함
# 4. 아니 그런데 SUM을 하면 Python이랑 C# 2개의 코드가 합한 값을 반환할 텐데 괜찮은 걸까? 생각했지만 어차피 & 연산을 했을때 단 1개라도 맞으면 0보다 큰 값을 반환할 것이기 때문에 문제가 없다!
# 5. sql은 & 연산을 하면 &에 합당한 모든 비트들의 값을 합하여 반환하는것으로 보인다! ex) 15(1111) & 14(1110) = 14(1110)

SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS
WHERE (SKILL_CODE & (SELECT SUM(CODE)
       FROM SKILLCODES
       WHERE NAME IN ("Python", "C#") ) ) > 0
ORDER BY ID