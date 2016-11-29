package HW1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class HW1 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		try{
		FileReader inputFile = new FileReader("input.txt");
		BufferedReader in = new BufferedReader(inputFile);
		
		String min1 = in.readLine();
		String max1 = in.readLine();
		String ans1 = in.readLine();
		
		int min = Integer.valueOf(min1);	
		int max = Integer.valueOf(max1);	
		int ans = Integer.valueOf(ans1);
		
		 Scanner scanner = new Scanner(System.in);
        
		int myans=1;
		
		while(myans!=ans){
				System.out.println("please guess an integer number between "+min+" and "+max+"");
				myans=scanner.nextInt();
				if (myans > ans&myans <= max){
					max = myans;
				}
				else if (myans < ans&myans >= min){
					min = myans;
				}
				else if (myans == ans){
					System.out.println("bingo");
					break;
				}
				else{
				    throw new IOException();//¥á¥X¿ù»~µ¹catch
				}
			}
		}
	    catch(IOException e)
		{
			System.out.println("The number you entered is not  within the valid range");
		}
	}
}