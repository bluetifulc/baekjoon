-- 59035 역순 정렬하기
SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY ANIMAL_ID DESC
-- 59034 모든레코드조회하기
SELECT * from ANIMAL_INS ORDER BY ANIMAL_ID
-- 59415 최댓값 구하기
SELECT DATETIME FROM ANIMAL_INS ORDER BY DATETIME DESC LIMIT 1
-- 59406 동물 수 구하기
SELECT COUNT(*) from ANIMAL_INS
-- 59040 고양이와 개는 몇 마리 있을까
SELECT ANIMAL_TYPE, COUNT(*) AS count FROM ANIMAL_INS 
GROUP BY ANIMAL_TYPE HAVING ANIMAL_TYPE="Cat" OR ANIMAL_TYPE="Dog"
ORDER BY ANIMAL_TYPE
-- 59046 루시와 엘라 찾기
SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE FROM ANIMAL_INS
WHERE NAME IN ("Lucy", "Ella", "Pickle", "Rogan", "Sabrina", "Mitty")
-- 59403 동물의 아이디와 이름
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS ORDER BY ANIMAL_ID
-- 59047 이름에 el이 들어가는 동물 찾기
SELECT ANIMAL_ID,NAME
FROM ANIMAL_INS 
WHERE NAME LIKE '%el%' AND ANIMAL_TYPE='Dog' 
ORDER BY NAME
-- 131536 재구매가 일어난 상품과 회원 리스트 구하기
SELECT DISTINCT USER_ID, PRODUCT_ID
FROM ONLINE_SALE
GROUP BY USER_ID, PRODUCT_ID
HAVING COUNT(*) > 1
ORDER BY USER_ID ASC, PRODUCT_ID DESC
-- 131123즐겨찾기가 가장 많은 식당 정보 출력하기 - 답1
SELECT REST_INFO.FOOD_TYPE, REST_INFO.REST_ID, REST_INFO.REST_NAME, REST_INFO.FAVORITES
FROM REST_INFO JOIN (
    SELECT FOOD_TYPE, MAX(FAVORITES) as m
    FROM REST_INFO
    GROUP BY FOOD_TYPE
) as T
ON REST_INFO.FOOD_TYPE=T.FOOD_TYPE and REST_INFO.FAVORITES=T.m
ORDER BY REST_INFO.FOOD_TYPE DESC
-- 131123즐겨찾기가 가장 많은 식당 정보 출력하기 - 답2
SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
FROM REST_INFO as A
WHERE A.FAVORITES=(
    SELECT MAX(B.FAVORITES) 
    FROM REST_INFO as B 
    WHERE A.FOOD_TYPE=B.FOOD_TYPE
)
ORDER BY FOOD_TYPE DESC