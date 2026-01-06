impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut min = 100001;
        let mut neg = 0;
        let mut zero = false;
        let mut ans: i64 = 0;
        for i in &matrix {
            for j in i {
                if *j < 0 {
                    neg += 1;
                } else if *j == 0 {
                    zero = true;
                }
                if j.abs() < min {
                    min = j.abs();
                }
                ans += j.abs() as i64;
            }
        }
        if neg % 2 != 0 && !zero {
            ans -= min as i64 * 2;
        }
        return ans;
    }
}
