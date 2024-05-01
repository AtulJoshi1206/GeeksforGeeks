//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class Node {
    char data;
    Node next;
    
    public Node(char data){
        this.data = data;
        next = null;
    }
}

class GFG {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    Node head = null, tail = null;
		    
		    char head_c = sc.next().charAt(0);
		    head = new Node(head_c);
		    tail = head;
		    
		    while(n-- > 1){
		        tail.next = new Node(sc.next().charAt(0));
		        tail = tail.next;
		    }
		    
		    Solution obj = new Solution();
		    //show(head);
		    show(obj.arrangeCV(head));
		    
		}
	}
	
	public static void po(Object o){
	    System.out.println(o);
	}
	
	public static void show(Node head){
        while(head != null){
            System.out.print(head.data+" ");
            head = head.next;
        }
        System.out.println();
    }
}

// } Driver Code Ends


/*
Structure of node class is:
class Node {
    char data;
    Node next;
    
    public Node(char data){
        this.data = data;
        next = null;
    }
}
*/
class Solution {
    //Bruteforce approach
    public Node arrangeCV(Node head){
        //write code here and return the head of changed linked list
        List<Character> set = new ArrayList<>();
        List<Character> consonants = new ArrayList<>(); 
        Node curr = head;
        
        while(curr != null){
            char d = curr.data;
            if(d == 'a' || d == 'e' || d == 'i' || d == 'o' || d =='u'){
                set.add(d);
            }else{
                consonants.add(d);
            }
            curr = curr.next;
        }
        Node current = new Node('0');
        Node arrange = current;
        for(char c : set){
            Node vowel = new Node(c);
            current.next = vowel;
            current = vowel;
            // System.out.print(c + " ");
        }
        
        for(char c : consonants){
            Node con = new Node(c);
            current.next = con;
            current = con;
            // System.out.print(c + " ");
        }
        return arrange.next;
    }
}

