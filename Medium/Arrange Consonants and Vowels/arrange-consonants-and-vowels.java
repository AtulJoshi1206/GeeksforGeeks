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
    // Rearrange the linked list such that all vowels come before consonants
    public Node arrangeCV(Node head) {
        if (head == null || head.next == null)
            return head; // If the list is empty or has only one node, no rearrangement needed

        Node vowelHead = new Node('0'); // Dummy head for vowels
        Node consonantHead = new Node('0'); // Dummy head for consonants
        Node vowel = vowelHead, consonant = consonantHead;

        // Traverse the original list
        for (Node curr = head; curr != null; curr = curr.next) {
            if (isVowel(curr.data)) {
                vowel.next = curr;
                vowel = curr;
            } else {
                consonant.next = curr;
                consonant = curr;
            }
        }

        // Connect the end of the vowel list to the beginning of the consonant list
        vowel.next = consonantHead.next;
        // Set the end of the consonant list to null to terminate it
        consonant.next = null;

        // Return the next node after the dummy head of the vowel list
        return vowelHead.next;
    }

    // Helper method to check if a character is a vowel
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}

