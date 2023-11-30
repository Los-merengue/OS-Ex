//Process With 2 Resources Used the same way

typedef int semaphore;
    semaphore resource 1;
    semaphore resource 2;
    
    void process A(void) {
        down(&resource 1);
        down(&resource 2);
        use both resources( );
        up(&resource 2);
        up(&resource 1);
    }

void process B(void) {
    down(&resource 1);
    down(&resource 2);
    use both resources( );
    up(&resource 2);
    up(&resource 1);
}

//Process with 2 Resources that are used Differently

semaphore resource 1;
semaphore resource 2;
void process A(void) {
    down(&resource 1);
    down(&resource 2);
    use both resources( );
    up(&resource 2);
    up(&resource 1);
}

void process B(void) {
    down(&resource 2);
    down(&resource 1);
    use both resources( );
    up(&resource 1);
    up(&resource 2);
}