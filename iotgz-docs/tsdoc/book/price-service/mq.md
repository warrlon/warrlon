# Message Queue MQ Pricing

> The current message queue MQ is free of charge. Before charging, we will notify you by telephone, short message, mail and so on. Please feel free to use it.

## Accounting Note
- Payment method

    Message queue MQ is a post-paid product. After service is opened, the cost is settled periodically according to service consumption.

- Cost Composition

    The cost of OneNET message queue MQ is mainly composed of ** message processing fee ** and ** topic usage fee **.

## Message processing fee

After the user opens the service instance, OneNET will count the number of message processing items in ** per day ** in a single service instance, and settle them at ** 0 o'clock per day ** based on ** 1.2 yuan per million messages per unit price ** at exactly two decimal points.

> Among them:
>- The rule for calculating the total amount of message processing is: the total number of message processing bars = the number of production bars + the number of consumed bars
> 
>- Measuring the number of individual message bodies: the size of a single message body / 1k, rounded up
>
> Calculate Example 1: Produce 1 message, message body size 1.5k, message consumed 1 time, message number 2 + 2 = 4
> Calculate Example 2, produce 1 message, message body size is 0.5k, message is consumed 2 times, message number is 1 + 2 = 3

#### Examples of billing

- From 00:00 on September 20, 2018 to 00:00 on September 21, 2018, a total of 3,514,540 messages were processed in user service instances, and the cost for that day was 3,514,540/1,000,000* 1.20 = 4.21 yuan.
- From 00:00 on September 21, 2018 to 00:00 on September 22, 2018, a total of 140,987 messages were processed in user service instances, and the cost for that day was 140,987/1,000,000*1.20 = 0.16 yuan.

#### Free instructions

Free use of the first 20 million messages per service instance per month


## Topic usage fee

After users create topics in service instances, OneNET will count the number of ** topics per day in service instances and settle accounts per day based on unit price of 2 yuan per day.

The formula for calculating topic usage fee is as follows:

    Topic usage fee for a day = unit price (2 yuan per day) = (number of topics at 0:00 on that day + number of new topics added in that day)

> ** Reminds **
>  
> Do not create a large number of temporary topics for testability, so as not to incur a large number of unnecessary costs
> Delete topics that are no longer in use in time to avoid unnecessary cyclical costs


#### Examples of billing

- On September 20, 2018, the user created a topic in the service instance, and from September 21, 2018 at 00:00, the user generated a 2 yuan daily top usage fee at 00:00.
- On September 21, 2018, there was already a topic in the user's service instance. On that day, a topic was created. From 00:00 on September 22, 2018, the topic usage fee of $4 per day was generated at 00:00.


## Account statement

OneNET Message Queue MQ bills at 0:00 a.m. a day, and the charges are automatically deducted from the account balance.

## Explanation of arrears
- At present, your account balance is not enough to pay the bills, OneNET will suspend your arrears instance, your service instance will no longer receive message production, and the client will not be able to consume the message, the message in the original queue will be released according to the expiration time of the message.
- If the default state exceeds 7 days, OneNET will release the service instance in the default state, the unprocessed message will be automatically released, and the released resources and messages will not be recovered.