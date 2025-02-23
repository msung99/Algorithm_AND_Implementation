class Solution {
    public int solution(String s) {
        
        int answer = s.length();
		
		for(int i=1; i<=s.length()/2; i++) {
			int zipLength = 1;
			String zipStr = s.substring(0, i); // 압축할 문자(문자열의 0번째부터 i-1번째까지)
			StringBuilder sb = new StringBuilder(); // 압축 완료된 문자열을 붙이면서 새로 만들 문자열
			
			for(int j=i; j<=s.length(); j+=i) { // i, 즉 앞축할 문자열 길이 만큼 j를 증가시켜줌
				String nextStr = s.substring(j, (j + i > s.length()) ? s.length() : j + i); // 다음 문자열에 j부터 j+i-1까지, 근데 배열 끝 이상으로까지 넘어가면 그냥 그 문자열의 길이-1 만큼 넣음
				
				if(zipStr.equals(nextStr)) {
					zipLength++;//같으면 그냥 압축 갯수 +1
				} else {
					//다음 문자열이 반복되는(즉, 앞의)문자열과 다르면 
					sb.append((zipLength != 1 ? zipLength : "") + zipStr); // 압축이 안 됏으면 그냥 공백(""), 압축이 됏으면 압축된 갯수 넣고 뒤에 그 압축문자열 단위 바로 붙임
					zipStr = nextStr;//방금 붙인 문자열을 새로운 압축 문자열로 등록해줌
					zipLength = 1; // 앞의 문자열과 달랏으니깐 새로운 압축갯수로 초기화 해 줌
				}
			}
			
			sb.append(zipStr); // 마지막꺼는 안붙여줫으니깐 여기서 붙여줌
			
			answer = Math.min(answer, sb.length()); // 최소값 찾음
		}
        
        return answer;
    }
}
