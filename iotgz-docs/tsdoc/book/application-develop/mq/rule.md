# Rule Configuration

OneNET supports user-defined data flow-based data forwarding rules
- Forwarding all data streams
- Selecting Data Flow Based on Data Flow Template
- Use regular expressions to customize matching rules for data stream names

## Regular expression usage

OneNET supports users to use regular expressions to customize filtering matching rules for data stream names when filtering data stream names.

### Example 1: Select all data streams

The reference filter expression is:

    .*

### Example 2: Precise filtering of a data stream

Expressional grammar:

    Data stream name

perhaps

    ^ Data stream name$

** Example **: If you need to select only CCC from aaa, BBB and CCC data streams, the reference filter expression is as follows:

    ccc

perhaps

    ^ccc$


### Example 3: Precise filtering of multiple data streams

Expressional grammar:

    Data Stream Name 1 | Data Stream Name 2 | Data Stream Name 3

perhaps

    ^ Data Stream Name 1 $|^ Data Stream Name 2 $|^ Data Stream Name 3$

If you need to select only aaa, BBB and CCC from these data streams, the reference filter expression is as follows:

    aaa|ccc

perhaps

    ^aaa$|^ccc$

### Example 4: Fuzzy filtering data flow

(1) If it is necessary to select only the data stream containing BC (abc, bcd, cde) from the abc, BCD and CDE data streams, the reference filter expression is as follows:

    .*bc.*

(2) If you need to select only test0, test1, test2, test3, abctest0 from these data streams, the reference filter expression is:

    ^test[0-2]


### Example 5: Multiple filtered data streams

If you need to select only test0, test01, humi2, humi3, abctest0 from these data streams, the reference filter expression is:

    ^test0.*|humi2


## More help

-[View the Console Use Guide](/book/easy-manual/MQ.md)
-[See more introduction to service functions](/book/application-development/mq/introduction.md)
-[For more information on client development assistance, see the Development Manual](/book/application-development/mq/development-manual.md)
-[View demo engineering instructions](/book/application-development/mq/demo-project.md)
-[View the best examples of service usage](/book/application-development/mq/example.md)
-[Restrictions on the use of public beta service resources](/book/application-development/mq/limit.md)