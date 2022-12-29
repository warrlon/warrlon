# Development process

In view of the difficulties of enterprises and developers in informing users, low real-time, easy to shield APP messages, and easy to ignore, OneNET launched a new short message service. Integrating three-network short message has the characteristics of development-free, low latency and high reliability. Support authentication code, short message notification and promotion of short messages. Support SMS group sending, status report acquisition, data statistics query and other functions.

### Short Message Ability

Before using SMS capabilities, you need to authenticate as an enterprise user in real name on OneNET platform. After the authentication is completed and the SMS capability is enabled, you will get the corresponding SIcode. SIcode is the core data for calling API interface and purchasing package. Please keep it properly and do not disclose it.

### Buy packages

Before sending a short message, you need to make sure that you have sufficient text message margin. You can buy packages on the platform. After successful purchase, the number of packages will be added to your balance. If it involves excessive purchases, you can contact customer service personnel.

### Application for signature

The short message sent by the short message service must be signed. The signature represents the identity of the sender. Signatures need to be submitted for verification before they can be used.


### Application template

Short message service only supports template short message sending. Short message template is divided into verification code, short message notification and promotion short message. Different types of SMS use different templates and follow different template specifications. Templates need to be audited before they can be used. Once the template is approved or rejected, it will not be able to modify the content of the template, and a new template needs to be applied for separately.

According to different template types, the corresponding specifications should be followed. Please select the template type according to the requirements.

Verification code: Verification code template only supports validation code as a unique variable, variable replacement value <= 6 digits or letters.

Short Message Notification: Short Message Notification Template supports multiple variables.

Promotion SMS: Adding variables is not supported. Support for reply to unsubscribe.

Variables in the template are surrounded by two half corners. Variable names can be English (case-sensitive), numeric and underscored. For example # code #, # user_name #.

The SMS template also needs to support the following common specifications:

All templates prohibit sending all financial-related content.

Does not support sending unauthorized sending behavior, mainly refers to the invitation to register, invite to become a member of the commercial information.

The prohibition of sending involves pornography, gambling, drugs, party and government, legal rights protection, public fund-raising, charitable fund-raising, religion, superstition, stocks, immigrants studying abroad, interview and recruitment, gambling, loans, remittances, credit card withdrawals, investment and financial management, winning prizes, drawing prizes, one-dollar treasure-winning, one-dollar second killing, one-dollar cloud buying, two types of e-commerce, goods A, plastic surgery, tobacco and alcohol, making friends, violence, fear. Short message of information such as scare, fur, cash rebate, proxy invoice, information prohibited by operators, agent registration, proxy certificate, group addition, QQ or Wechat, selling personal information, operator countermeasure, traffic marketing, violation of advertising terms, funeral, bill-brushing, empty bag network, invitation of high praise, shop-changing business, etc.

The occurrence of mistyped characters, variants, variants, interference symbols, etc. in key words or key information is prohibited; all kinds of abnormal mixed words and unusual expressions are prohibited.

The content does not support direct or indirect access to the application internal test distribution platform.

Real estate, overseas study, recruitment and other industries only support sending validation code short messages.