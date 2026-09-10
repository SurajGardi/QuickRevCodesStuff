class StringDemo1
{
    public static void main(String A[])
    {
        String s1 = "Hello";

        String s2 = new String("Hello");
    
        char Arr[] = {'H','e','l','l','o'};

        String s3 = new String(Arr);

        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);
    }
}